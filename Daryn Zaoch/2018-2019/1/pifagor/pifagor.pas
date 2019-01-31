var 
	a, b, c, d : Longint;
	i		   : Integer;
	Z		   : Integer;		
begin
	assign(input,'input.txt');reset(input); 
	assign(output,'output.txt');rewrite(output); 
	readln (a, b, c, d);
    Z := 0;
	for i:= 1 to 10000 do begin
		if (i mod a = 0) and (i mod b = 0) and (i mod c = 0) and ((i div a) + (i div b) + (i div c) + d = i) then
		begin
			writeln(i);
			Z := 1;	
			break;
		end;
	end;	
	if (Z <> 1) then
	begin
		writeln(-1);
	end;
	close(output);
end.
