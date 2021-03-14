classdef interpObj2d < handle
    properties
        minVal %min value across each dimension
        maxVal %max value across each dimension
        orderNS %ordered points from north to south (1st coordinate)
        orderEW %ordered points from east to west (2nd coordinate)
        indiceNS %order of points
        indiceEW %order of points
        pointsN %order of points from north to south
        pointsE %order of points from east to west
        trianglesN %check if each triangle node is north of query
        trianglesE %check if each triangl   e node is east of query
        indexN %this is the first point north of the query
        indexE %this is the first point east of the query
        lastQuery %the last coordinate queried
        properT %boolean T array for the correct triangle
        P %points array
        T %triangle array
        nodeVals %value at each point/node
    end
    
    methods
        function obj=interpObj2d(Pmat,Tmat,nVals)
            obj.maxVal = [max(Pmat(:,1)),max(Pmat(:,2))];
            obj.minVal = [min(Pmat(:,1)),min(Pmat(:,2))];
            [obj.orderNS,obj.indiceNS] = sort(Pmat(:,1));
            [obj.orderEW,obj.indiceEW] = sort(Pmat(:,2));
            obj.pointsN = zeros([size(Pmat,1),1]);
            obj.pointsE = zeros([size(Pmat,1),1]);
            obj.trianglesN = zeros(size(Tmat));
            obj.trianglesE = zeros(size(Tmat));
            obj.lastQuery = [(obj.minVal(1)+obj.maxVal(1))/2,(obj.minVal(2)+obj.maxVal(2))/2];
            obj.indexN = closest_value(obj.orderNS,(obj.minVal(1)+obj.maxVal(1))/2);
            obj.indexE = closest_value(obj.orderEW,(obj.minVal(2)+obj.maxVal(2))/2);
            obj.pointsN(obj.indiceNS(obj.indexN:end)) = 1;
            obj.pointsE(obj.indiceEW(obj.indexE:end)) = 1;
            obj.properT = zeros([size(Tmat,1),1]);
            obj.P = Pmat;
            obj.T = Tmat;
            obj.nodeVals = nVals;
        end
        function obj = resetIndex(obj,query)
            obj.indexN(:) = closest_value(obj.orderNS,query(1));
            obj.indexE(:) = closest_value(obj.orderEW,query(2));
%             if query(1) >= obj.lastQuery(1)
%                obj.indexN = closest_value(obj.orderNS,query(1),obj.indexN+1);
%            else
%                obj.indexN = closest_value(obj.orderNS,query(1),1,obj.indexN);
%            end
%            if query(2) > obj.lastQuery(2)
%                obj.indexE = closest_value(obj.orderEW,query(2),obj.indexE+1,length(obj.orderEW));
%            else
%                obj.indexE = closest_value(obj.orderEW,query(2),1,obj.indexE);
%            end
           obj.lastQuery = query;
           obj.locateIndex();
           obj.sortTri();
        end
        function obj=resetQuery(obj)
        	obj.lastQuery(:) = [(obj.minVal(1)+obj.maxVal(1))/2,(obj.minVal(2)+obj.maxVal(2))/2];
            obj.indexN(:) = closest_value(obj.orderNS,(obj.minVal(1)+obj.maxVal(1))/2);
            obj.indexE(:) = closest_value(obj.orderEW,(obj.minVal(2)+obj.maxVal(2))/2);
        end
        function value=interp2d(obj,query)
           obj.resetIndex(query);
           triInd = obj.findTri();
           value = obj.interpOp(triInd,query);
        end
        function value = interpOp(obj,indTri,query)
            baryCoord = findBary(obj.P(obj.T(indTri,:),:),query);
            triVals = obj.nodeVals(obj.T(indTri,:));
            value = dot(baryCoord,triVals);
        end
        function locateIndex(obj)          
            obj.pointsN(obj.indiceNS(1:obj.indexN-1)) = 0;
            obj.pointsN(obj.indiceNS(obj.indexN:end)) = 1;
            obj.pointsE(obj.indiceEW(1:obj.indexE-1)) = 0;
            obj.pointsE(obj.indiceEW(obj.indexE:end)) = 1;
        end
        
        function sortTri(obj)
           obj.trianglesN(:,:) = obj.pointsN(obj.T);
           obj.trianglesE(:,:) = obj.pointsE(obj.T);
           sumN = sum(obj.trianglesN,2);
           sumE = sum(obj.trianglesE,2);
           obj.properT(:,:) = (sumN > 0 & sumN < 3) & (sumE > 0 & sumE < 3);
        end
        
        function triInd = findTri(obj)
            triInd = find(obj.properT == 1,1);
        end
        
        function vals = getMin(obj)
            vals = obj.minVal;
        end
        function vals = getMax(obj)
            vals = obj.maxVal;            
        end
        function vals = getNS(obj)
            vals = obj.orderNS;
        end
        function vals = getEW(obj)
            vals = obj.orderEW;
        end
        function coord = genCoord(obj)
           xPart = rand()*(obj.maxVal(1)-obj.minVal(1))+obj.minVal(1); 
           yPart = rand()*(obj.maxVal(2)-obj.minVal(2))+obj.minVal(2); 
           coord = [xPart,yPart];
        end
        function state = testWithin(obj,coord)
            state = 1;
            if coord(1) > obj.maxVal(1) && coord(1) < obj.minVal(1)
                state = 0;
            end
            if coord(2) > obj.maxVal(2) && coord(2) < obj.minVal(2)
                state = 0;
            end
        end
        function state = testInd(obj)
            state = 1;
            if obj.lastQuery(1) <= obj.orderNS(obj.indexN-1) || obj.lastQuery(1) > obj.orderNS(obj.indexN)
                state = 0;
                disp("ERROR NS")
                disp([obj.orderNS(obj.indexN-1),obj.lastQuery(1),obj.orderNS(obj.indexN)])
            end
            if obj.lastQuery(2) <= obj.orderEW(obj.indexE-1) || obj.lastQuery(2) > obj.orderEW(obj.indexE)
                state = 0;
                disp("ERROR EW")
                disp([obj.orderEW(obj.indexE-1),obj.lastQuery(2),obj.orderEW(obj.indexE)])
            end
        end
    end
end

function ind = closest_value(A, val)
    %if ~exist('floorInd','var')
    floorInd = 1;
    %end
    %if ~exist('ceilInd','var')
    ceilInd = length(A);
    %end
    while ceilInd - floorInd > 1
        med = floor((floorInd + ceilInd)/2);
        if A(med) >= val 
            ceilInd = med;
        else
            floorInd = med;
        end
    end

    if ceilInd - floorInd == 1 && (A(floorInd) <= val && A(ceilInd) > val)
        ind = ceilInd;
    else
        ind = 0;
    end  
end

function bCoord = findBary(triCoords,query)
    v0 = triCoords(2,:)- triCoords(1,:);
    v1 = triCoords(3,:)- triCoords(1,:);
    v2 = query- triCoords(1,:);
    d00 = dot(v0,v0);
    d01 = dot(v0,v1);
    d11 = dot(v1,v1);
    d20 = dot(v2,v0);
    d21 = dot(v2,v1);
    denom = d00 * d11 - d01 * d01;
    v = (d11 * d20 - d01 * d21) / denom;
    w = (d00 * d21 - d01 * d20) / denom;
    u = 1 - v - w;
    bCoord = [u,v,w];
end


