program Serzhan;
Type 
Vector = array [1..30] of Longint; 
Matrix= array [1..30] of vector;
Var A : matrix;
i, j : integer;
n, m : integer;
sum : integer;
cnt : integer;
begin
	Readln(n, m);
	Write(n, m);
	sum := 0;
	cnt := 0;
	for i :=1 to n do 
      for j :=1 to m do         
      	read ( a [ i , j ]);		
	for i := 1 to n do
		for j := 1 to m do
			IF a[i, j] > 0 then
				begin
				cnt := cnt + 1;
				sum := sum + a[i, j];
				end;
	Write(sum, ' ', cnt);
end. 
