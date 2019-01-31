var 
	a, b, n : LongInt;	
	i : integer;
	cnt : integer;
begin
	assign(input,'input.txt');reset(input); 
	assign(output,'output.txt');rewrite(output); 
	readln(a, b, n);
	cnt := 0;
	for i:=0 to n - 1 do
	begin
		if a * i mod n = b then
		begin
			inc(cnt);
		end;
	end;
	write(cnt);
	close(output);
end.
