const
    m = 10000;

var
    arr: array[1..m] of integer;
    i, j, k: integer;
	n: integer;
	cnt: integer;
begin
	assign(input,'input.txt');reset(input); 
	assign(output,'output.txt');rewrite(output); 
	
	readln(n);
	for i := 1 to n do begin	
		read(arr[i]);
	end;
	for i := 1 to n-1 do
        for j := 1 to n-i do
            if arr[j] > arr[j+1] then begin
                k := arr[j];
                arr[j] := arr[j+1];
                arr[j+1] := k
            end;
	for i := 1 to n do 
	begin
		if (i = 1) then
		cnt := 1
		else if (arr[i - 1] <> arr[i]) then
		inc(cnt);
	end;
	Writeln(cnt);
	close(output);
end.
