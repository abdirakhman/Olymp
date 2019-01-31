program divisible;
var s : string;
    x, i : Longint;
begin
	assign(input,'input.txt');reset(input); 
	assign(output,'output.txt');rewrite(output); 
	readln(s);
	while(length(s) mod 3 > 0) do s := '0' + s;
	x := 0;
	i := 1;
	while(i <= length(s)) do begin
		x := x + (ord(s[i]) - 48) * 4 + (ord(s[i + 1]) - 48) * 2 + ord(s[i + 2]) - 48;
		i := i + 3;
	end;
	if x mod 7 = 0 then writeln('ДА') else writeln('НЕТ');	
	close(output);
end.
