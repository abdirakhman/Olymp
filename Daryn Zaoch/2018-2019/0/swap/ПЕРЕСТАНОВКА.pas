program swap;
var a, b : LongInt;
begin
	assign(input,'input.txt');reset(input); 
	assign(output,'output.txt');rewrite(output); 
    read(a, b);
    a := a + b;
	b := a - b;
	a := a - b;
	write(a, ' ', b);
	close(output);
end.