function found = bfs(adj_mat, start_node, end_node,vertices,edges )

%% do breadth first search

%define a queue
queue = CQueue();

%define a visited array to keep track of vertices which has been visited so
%far

visited = zeros(1,vertices);
in_queue = zeros(1,vertices);
queue.push(start_node);
in_queue(1,start_node)=1;

while ~queue.isempty()
    current_value = queue.pop();
    fprintf(1,'value: %d\n',current_value)
    if(current_value == end_node)
        found= 1;
        fprintf(1,'found!!!!\n')
        break
    end
    visited(1,current_value)=1;
    %check for all elements that are connected to current_value
    for i = 1:vertices
        if adj_mat(current_value,i)==1
            if ~visited(1,i)
                if ~in_queue(1,i)
                    queue.push(i);
                    in_queue(1,i)=1;
                end
            end
        end
    end
end

end

