function interpVal = rectInterp2d(query,dim1_val,dim2_val,vGrid)
    ind1 = closest_val(dim1_val,query(1));
    ind2 = closest_val(dim2_val,query(2));

    dist_NE = (query(1)-dim1_val(ind1))^2 + (query(2)-dim2_val(ind2))^2;
    dist_NW = (query(1)-dim1_val(ind1))^2 + (query(2)-dim2_val(ind2-1))^2;
    dist_SW = (query(1)-dim1_val(ind1-1))^2 + (query(2)-dim2_val(ind2))^2;
    dist_SE = (query(1)-dim1_val(ind1-1))^2 + (query(2)-dim2_val(ind2-1))^2;
    total_dist = dist_NE + dist_NW + dist_SW + dist_SE;

    val_NE = dist_NE*vGrid(ind1,ind2)/total_dist;
    val_NW = dist_NW*vGrid(ind1,ind2-1)/total_dist;
    val_SW = dist_SW*vGrid(ind1-1,ind2)/total_dist;
    val_SE = dist_SE*vGrid(ind1-1,ind2-1)/total_dist;

    interpVal = val_NE + val_NW + val_SW + val_SE;
end

function ind = closest_val(A, val)
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
