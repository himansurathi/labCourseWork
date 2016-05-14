% rc=1;
% rcc=2;
% lc=3;
% lcc=4;
% uc=5;
% ucc=6;
% dc=7;
% dcc=8;
% fc=9;
% fcc=10;
% bc=11;
% bcc=12;


function rubicsCube()
    mat=zeros(3,3,6);
  %  goal=zeros(3,3,6);
    disp('Enter input state: ');
    for i=1:6
        mat(:,:,i)=input('');
    end
%     disp('Enter goal state: ');
%     for i=1:6
%         goal(:,:,i)=input('');
%     end
    disp(mat); 
    val=eval(mat);
    
    while val~=0  
        x=1;
        sol=moverc(mat);
        fx=eval(sol);
        
        cube=movercc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=movelc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=movelcc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=moveuc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=moveucc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=movedc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=movedcc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=movefc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=movefcc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=movebc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
        
        cube=movebcc(mat);
        [sol,x,fx]=compareFx(sol,cube,x,fx);
  
         mat=sol(:,:,:,randi(x,1,1));
         disp(mat);   
         input('');
    end
end

function [sol,x,fx]=compareFx(sol,cube,x,fx)
    fx2=eval(cube);
    if fx2<fx
        sol=cube;
        x=1;
        fx=fx2;
    elseif fx2==fx
        x=x+1;
        sol(:,:,:,x)=cube;
    end
end


function [result]=eval(mat)
    result=0; 
    for i=1:6
       for j=1:3
           for k=1:3
               if mat(j,k,i)~=mat(2,2,i)
                   result=result+1;
               end
           end
       end
    end
end


function mat=moverc(mat)
    mat(:,:,2)=rot90(mat(:,:,2),3);
    temp=mat(:,3,1);
    mat(:,3,1)=mat(:,3,6);
    mat(:,3,6)=mat(:,3,3);
    mat(:,3,3)=mat(:,3,5);
    mat(:,3,5)=temp;
end

function mat=movercc(mat)
    mat(:,:,2)=rot90(mat(:,:,2),1);
    temp=mat(:,3,1);
    mat(:,3,1)=mat(:,3,5);
    mat(:,3,5)=mat(:,3,3);
    mat(:,3,3)=mat(:,3,6);
    mat(:,3,6)=temp;
end

function mat=movelc(mat)
    mat(:,:,4)=rot90(mat(:,:,4),3);
    temp=mat(:,1,1);
    mat(:,1,1)=mat(:,1,5);
    mat(:,1,5)=mat(:,1,3);
    mat(:,1,3)=mat(:,1,6);
    mat(:,1,6)=temp;
end

function mat=movelcc(mat)
    mat(:,:,2)=rot90(mat(:,:,2),1); 
    temp=mat(:,1,1);
    mat(:,1,1)=mat(:,1,6);
    mat(:,1,6)=mat(:,1,3);
    mat(:,1,3)=mat(:,1,5);
    mat(:,1,5)=temp;
end


function mat=moveuc(mat)
    mat(:,:,5)=rot90(mat(:,:,5),3);
    temp=mat(1,:,1);
    mat(1,:,1)=mat(1,:,2);
    mat(1,:,2)=mat(1,:,3);
    mat(1,:,3)=mat(1,:,4);
    mat(1,:,4)=temp;
end

function mat=moveucc(mat)
    mat(:,:,5)=rot90(mat(:,:,5),1);
    temp=mat(1,:,1);
    mat(1,:,1)=mat(1,:,4);
    mat(1,:,4)=mat(1,:,3);
    mat(1,:,3)=mat(1,:,2);
    mat(1,:,2)=temp;
end

function mat=movedc(mat)
    mat(:,:,6)=rot90(mat(:,:,6),3);
    temp=mat(3,:,1);
    mat(3,:,1)=mat(3,:,4);
    mat(3,:,4)=mat(3,:,3);
    mat(3,:,3)=mat(3,:,2);
    mat(3,:,2)=temp;
end

function mat=movedcc(mat)
    mat(:,:,2)=rot90(mat(:,:,2),1); 
    temp=mat(3,:,1);
    mat(3,:,1)=mat(3,:,2);
    mat(3,:,2)=mat(3,:,3);
    mat(3,:,3)=mat(3,:,4);
    mat(3,:,4)=temp;
end


function mat=movefc(mat)
    mat(:,:,1)=rot90(mat(:,:,1),3);
    temp=mat(3,:,5);
    mat(3,:,5)=mat(:,3,4);
    mat(:,3,4)=mat(1,:,6);
    mat(1,:,6)=mat(:,1,2);
    mat(:,1,2)=temp;
end

function mat=movefcc(mat)
    mat(:,:,1)=rot90(mat(:,:,1),1);
    temp=mat(3,:,5);
    mat(3,:,5)=mat(:,1,2);
    mat(:,1,2)=mat(1,:,6);
    mat(1,:,6)=mat(:,3,4);
    mat(:,3,4)=temp;
end

function mat=movebc(mat)
    mat(:,:,1)=rot90(mat(:,:,1),3);
    temp=mat(1,:,5);
    mat(1,:,5)=mat(:,1,4);
    mat(:,1,4)=mat(3,:,6);
    mat(3,:,6)=mat(:,3,2);
    mat(:,3,2)=temp;
end

function mat=movebcc(mat)
    mat(:,:,3)=rot90(mat(:,:,3),1);
    temp=mat(1,:,5);
    mat(1,:,5)=mat(:,3,2);
    mat(:,3,2)=mat(3,:,6);
    mat(3,:,6)=mat(:,1,4);
    mat(:,1,4)=temp;
end