close all

s=serial('/dev/tty.usbserial-AJV9IJKO','BaudRate',9600);
set(s, 'BaudRate', 9600);
set(s, 'DataBits', 8);
set(s, 'StopBits', 1);
set(s, 'Parity', 'none');

fopen(s);

x=[];

i=0;

% VERIFY SERIAL COMMUNICATION HAS BEEN SETUP
a = 0;


try
    while (i<1000)
        i=i+1;
        
        a = fscanf(s,'%s');
        aa=sscanf(a,'%d,%d');
        disp(aa)
        if(length(aa) ==2)    
        


            x = [x;aa'];
            plot(x(:,1:2))
            legend('ax','ay')
            if (i>20)
                 axis([i-20 i 0 1100]);
            else
                 axis([1 i+1 0 1100]);     
            end
            
            
           
            drawnow;
        end
 
    end
    

end


fclose(s)
disp('end')

