function IsDigit(c:char):boolean;
begin
	IsDigit := c in ['0'..'9']
end;

var
	s : string;
	n : Integer;
	i : Integer;
	tot_sum : Integer;
	tmp_sum : Integer;
begin
	assign(input,'input.txt');reset(input); 
	assign(output,'output.txt');rewrite(output); 

		readln(s);
	n := length(s);
	tot_sum := 0;
	tmp_sum := 0;
	for i := 1 to n do 
	begin
		if IsDigit(s[i]) then
		begin
			tmp_sum := tmp_sum * 10 + Ord(s[i]) - 48;
		end
		else
		begin
			tot_sum := tot_sum + tmp_sum;
			tmp_sum := 0;	
		end;	
	end;
	if tmp_sum > 0 then
	begin
		tot_sum := tot_sum + tmp_sum;	
	end;
	write(tot_sum);
	close(output);


end.
