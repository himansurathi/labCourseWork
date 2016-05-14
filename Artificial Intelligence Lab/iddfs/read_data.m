function [adj_mat,start_node,end_node,vertices,edges,depth] = read_data()

%% Load graph data
fid = fopen('input.txt');
line12= fscanf(fid,'%d',5)
depth = line12(1,1);
vertices= line12(2,1);
edges= line12(3,1);
start_node = line12(4,1);
end_node = line12(5,1);

rest_lines = textscan(fid,'%d %d');
rest_lines_mat= cell2mat(rest_lines)
graph= rest_lines_mat
fclose(fid);

%% Store graph data into adjacency matrix
adj_mat = zeros(vertices);
for i = 1: edges
    x= graph(i,1);
    y= graph(i,2);
    adj_mat(x,y)=1;
end


end

