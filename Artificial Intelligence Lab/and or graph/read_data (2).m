function [adj_mat,and_mat,heuristic_mat,start_node,goal_node,vertices,edges,depth] = read_data()

%% Load graph data
fid = fopen('input2.txt');
line12= fscanf(fid,'%d',5)
vertices= line12(1,1);
edges= line12(2,1);
and_edges = line12(3,1)
start_node = line12(4,1)
goal_node = line12(5,1)

rest_lines = textscan(fid,'%d %d');
rest_lines_mat= cell2mat(rest_lines);
heuristic= rest_lines_mat(1:vertices,:);
and_lines= rest_lines_mat(vertices+1: vertices+and_edges,:);
graph= rest_lines_mat(vertices+and_edges+1:length(rest_lines_mat),:);
fclose(fid);

%% Store graph data into adjacency matrix
adj_mat = zeros(vertices);
and_mat= zeros(1,vertices);
heuristic_mat = zeros(1,vertices);
for i = 1: edges
    x= graph(i,1);
    y= graph(i,2);
    adj_mat(x,y)=1;
end

for j = 1:and_edges
    x= and_lines(j,1);
    y= and_lines(j,2);
    and_mat(1,x) = y;
    and_mat(1,y) = x;
end

heuristic
for k=1:vertices
    x= heuristic(k,1);
    y= heuristic(k,2);
    heuristic_mat(1,x)=y;
end

% adj_mat
 and_mat
 heuristic_mat
% 
% [val,heuristic_updated] = update_heuristic( adj_mat,and_mat,vertices,edges,heuristic_mat,1)
% heuristic_updated
end

