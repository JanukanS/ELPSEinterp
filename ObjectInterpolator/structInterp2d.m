function value=structInterp2d(obj,query)
   %obj.resetIndex(query);
   obj.indexN(:) = closest_value(obj.orderNS,query(1));
   obj.indexE(:) = closest_value(obj.orderEW,query(2));
   obj.lastQuery = query;
   
   %obj.locateIndex();
    obj.pointsN(obj.indiceNS(1:obj.indexN-1)) = 0;
    obj.pointsN(obj.indiceNS(obj.indexN:end)) = 1;
    obj.pointsE(obj.indiceEW(1:obj.indexE-1)) = 0;
    obj.pointsE(obj.indiceEW(obj.indexE:end)) = 1;
   
   %obj.sortTri();
   obj.trianglesN(:,:) = obj.pointsN(obj.T);
   obj.trianglesE(:,:) = obj.pointsE(obj.T);
   sumN = sum(obj.trianglesN,2);
   sumE = sum(obj.trianglesE,2);
   obj.properT(:,:) = (sumN > 0 & sumN < 3) & (sumE > 0 & sumE < 3);
   
   
   triInd = find(obj.properT == 1,1);
   
   %value = obj.interpOp(triInd,query);
   baryCoord = findBary(obj.P(obj.T(triInd,:),:),query);
   triVals = obj.nodeVals(obj.T(triInd,:));
   value = dot(baryCoord,triVals);
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

function sortTri(obj)
   obj.trianglesN(:,:) = obj.pointsN(obj.T);
   obj.trianglesE(:,:) = obj.pointsE(obj.T);
   sumN = sum(obj.trianglesN,2);
   sumE = sum(obj.trianglesE,2);
   obj.properT(:,:) = (sumN > 0 & sumN < 3) & (sumE > 0 & sumE < 3);
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
