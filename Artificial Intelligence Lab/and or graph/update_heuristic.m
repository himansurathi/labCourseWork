function [h,heu] = update_heuristic( adj_mat,and_mat,vertices,edges,heuristic_mat,current_node )
% fprintf(1,'current node----> %d\n',current_node)
%check if the current node is a terminal one
child_present= false;
for i=1:vertices
    if adj_mat(current_node,i)==1
        child_present=true;
        break;
    end
end

if child_present==false
    heu= heuristic_mat;
    h= heuristic_mat(1,current_node);
    %fprintf(1,'returning %d for %d\n',h,current_node);
    return;
end

val=1000;
%fprintf(1,'initial %d\n',val)
for i=1:vertices
    if adj_mat(current_node,i)==1
        %check if an AND arc is present and both of them has already been
        %processed
        if and_mat(1,i)>0 && and_mat(1,i) < i
            continue;
        end
        heuristic_mat(1,i) = update_heuristic( adj_mat,and_mat,vertices,edges,heuristic_mat,i );
        if and_mat(1,i)>0
            %AND arc present
            heuristic_mat(1,and_mat(1,i))= update_heuristic( adj_mat,and_mat,vertices,edges,heuristic_mat,and_mat(1,i));
            val = min(val, heuristic_mat(1,i)+heuristic_mat(1,and_mat(1,i))+2);
%             fprintf(1,'mat(1,%d) = %d ',i, heuristic_mat(1,i))
%             fprintf(1,'mat(1,and_mat(1,%d)) = %d \n',i, heuristic_mat(1,and_mat(1,i)))
%             fprintf(1,'change 2 %d\n',val)
        else
            val = min(val, heuristic_mat(1,i)+1);
            %fprintf(1,'change 3 %d\n',val)
        end
    end
end
%fprintf(1,'current node updated to %d',val);
%update the current node's heuristic to the minimum value of the child
%nodes' heuristic
% fprintf(1,'final %d\n',val)
% fprintf(1,'current node updated %d\n',current_node)
heuristic_mat(1,current_node)= val;
h= val;
heu=heuristic_mat;
end

