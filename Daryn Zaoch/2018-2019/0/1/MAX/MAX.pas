program max;
var x, mx : Longint;
function Max(a, b : Longint):Longint;
begin
	if a > b then Max := a else Max := b
end;

begin
	assign(input,'input.txt');reset(input); 
	assign(output,'output.txt');rewrite(output); 
	readln(x);
	mx := -1;
	while x > 0 do begin
		mx := Max(mx, (x mod 10));
		x := x div 10;
	end;
	write(mx);
	close(output);
end.