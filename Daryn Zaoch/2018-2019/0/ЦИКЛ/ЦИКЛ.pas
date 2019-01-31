program cycle;
var x, cnt, tmp : LongInt;
begin
    assign(input,'input.txt');reset(input); 
	assign(output,'output.txt');rewrite(output); 
	readln(x);
    cnt := 0;
    while x >= 10 do begin
    	tmp := x;
    	x := (tmp div 10) * (tmp mod 10);
    	cnt := cnt + 1;
    end;	
    Write(cnt);
    close(output);
end.