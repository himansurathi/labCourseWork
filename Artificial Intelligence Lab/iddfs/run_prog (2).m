%%
[adj_mat,start_node,end_node,vertices,edges,depth] = read_data();
found = iddfs(adj_mat,start_node,end_node,depth);
if found==1
    fprintf(1,'Found!\n')
else
    fprintf(1,'Not Found!\n')
end