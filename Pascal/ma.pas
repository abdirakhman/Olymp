program SERZHAN;
var 
	y	: Longint;
	x	: Longint;

begin
	Readln(x);
	IF (x < -2) then y := x * x + 2 * x + 2
	ELSE IF ((-2 <= x) and (x <= 2)) then y := - x * x + 7
	ELSE  y := 6;
	Write(y);
end.	