function found= sahc(adj_mat,and_mat,heuristic_mat,start_node,end_node,vertices)

change=1;
while change    
    best_node_wt=1000;
    best_node=0;
    
    fprintf(1,'%d\n',start_node)
    
    if(start_node==end_node)
        found=1;
        return;
    end
    
    for i=1:vertices
        edge_present = adj_mat(start_node,i);
        if edge_present>0
            wt= heuristic_mat(1,i);
            if and_mat(1,i)>0 && and_mat(1,i)<i
                continue;
            end
            if and_mat(1,i)>0
                wt= heuristic_mat(1,i) + heuristic_mat(1,and_mat(1,i));
            end
            if wt<best_node_wt
                best_node = i;
                best_node_wt = wt;
            end
        end
    end
    if best_node>0
            %fprintf(1,'best node %d best wt %d\n',best_node,best_node_wt)
            start_node = best_node;
    else
        change=0;
    end
end

found=0;
    
end
