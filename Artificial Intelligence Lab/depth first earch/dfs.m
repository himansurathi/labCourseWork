function found = dfs(adj_mat, start_node, end_node,vertices)

visited = zeros(1,vertices);

found = recursive_dfs(adj_mat,start_node,end_node,vertices);

if found
    fprintf(1,'found!\n')
else
    fprintf(1,'not found\n')
end

function found2 = recursive_dfs(adj_mat,start_node,end_node,vertices)

fprintf(1,'%d\n',start_node);
visited(1,start_node)=1;
if start_node== end_node
    found2=1;
    return
end

for i= 1:vertices
    if adj_mat(start_node,i)==1
        if ~visited(1,i)
            found2 = recursive_dfs(adj_mat,i,end_node,vertices);
            if found2
                return
            end
        end
    end
end

found2=0;

end


end
