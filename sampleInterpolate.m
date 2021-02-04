 global cnst
 
 % some initialization
 cnst = initCnst;             % will put more things in initCnst...

 
 
 % get the hydro profile
 dracoFile = "draco_EPsph_JFM.mat";

 % set the time slice here
 tslice = 11;                

 % variables to import/define set here:
 %
 addVarFlag.ne = true;
 addVarFlag.dLogNedz = true;
 addVarFlag.dLogNedr = true;
 addVarFlag.Dmn = false;
 addVarFlag.te = true;
 addVarFlag.ti = false;
 addVarFlag.dLnTedz = true;
 addVarFlag.dLnTedr = true;
 addVarFlag.Vz = true;
 addVarFlag.Vr = true;
 addVarFlag.Zbar = true;
 addVarFlag.Zsqr = true;
 
 % TO DO: add a function called "importAnalyticGrid()" that allows
 % you to define analytic hydro profiles, e.g. linearly varying
 % density, constant temperature and so on. Everything will still
 % be stored in the rayGd structure though.
 %

 if ~exist('rayGd','var')
     disp("loading hydro...")
     rayGdOriginal = importDracoGrid(dracoFile,tslice,addVarFlag);
     disp("done loading hydro")
 else
     disp("using exisiting hydro")
 end
 
 % update if the time slice has changed too
 if rayGdNew.iTime ~= tslice
     disp("updating hydro...")
     rayGdNew = importDracoGridAlt(dracoFile,tslice,addVarFlag,critNe);
     rayGdOriginal = importDracoGrid(dracoFile,tslice,addVarFlag);
     disp("done updating hydro")
 end

zLow = -800;
zHigh = 1300;
rLow = -1250;
rHigh = 1255; 

pointsList = rand(1000000,2);
pointsList(:,1) = (zHigh-zLow)*pointsList(:,1)+zLow;
pointsList(:,2) = (rHigh-rLow)*pointsList(:,2) + rLow;
times = [0,0];
tic
interpData1 = interpDT(rayGdOriginal.DT,rayGdOriginal.valsNe,pointsList);
times(1) = toc;


%original interpolation algorithm
function VqLin = interpDT(DT,ValsNe,PqList)
%DT - Delaunay Triangulation
%ValsNe - log density value at each given coordinate
%PqList - matrix with requested coordinates for interpolation: ordered
%[z,r]
    VqLin = zeros([size(PqList,1),1]);
    for i=1:size(PqList,1)
        [ti,bc] = pointLocation(DT,PqList(i,:));
        triVals = ValsNe(DT(ti,:));
        VqLin(i) = dot(bc',triVals')';
    end
end

