function found2 = dfs_depth(adj_mat,start_node,end_node,depth)

if depth<=0
    found2=0;
    return
end

fprintf(1,'%d\n',start_node);

if start_node == end_node
    found2=1;
    return
end


for i= 1:length(adj_mat)
    if adj_mat(start_node,i)==1
            found2 = dfs_depth(adj_mat,i,end_node,depth-1);
            if found2
                return
            end
    end
end
found2=0;
end