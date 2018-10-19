program SERZHAN;
type
	V = array[1..85] of Integer;
Var
	A : V;
	N : Integer;
	i : Integer;
	S : Longint;
begin
	Readln(N);
	S := 0;
	for i := 1 to N do
	begin
		read(A[i]);
		S := S + A[i];
	end;
	Writeln('Sani : ', N);
	writeln('Kosindisi:', S);

end.