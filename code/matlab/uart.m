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
        aa=sscanf(a,'%d,%d,%d,%d');
        disp(aa)
        if(length(aa) ==4)    
        
            if a ==200
                break;
            end

            x = [x;aa'];
            subplot(3,1,1);plot(x(:,1:2))
            legend('Consigne','Mesure')
            if (i>20)
                 axis([i-20 i 0 100]);
            else
                 axis([1 i+1 0 100]);     
            end
            
            
            subplot(3,1,2);plot(x(:,3))

            if (i>20)
                 
                 axis([i-20 i -100 100]);
            else
                 axis([1 i+1 -100 100]);
                 
            end
            legend('Erreur')
            
            subplot(3,1,3);plot(x(:,4))

            if (i>20)
                 
                 axis([i-20 i 0 100]);
            else
                 axis([1 i+1 0 100]);
                 
            end
            legend('Commande')
            
            drawnow;
        end
 
    end
    

end


fclose(s)
disp('end')

