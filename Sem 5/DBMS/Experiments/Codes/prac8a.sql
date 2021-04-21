8A

do $$

DECLARE
	n INTEGER; 
	temp_sum INTEGER; 
	r INTEGER; 
BEGIN
	n := 123456; 
	temp_sum := 0; 

	WHILE n <> 0 LOOP 
		r := MOD(n, 10); 
		temp_sum := temp_sum + r; 
		n := Trunc(n / 10); 
	RAISE NOTICE '%', temp_sum;
	END LOOP; 
END; 

$$ language plpgsql

8B

do $$

DECLARE
	i INTEGER;
BEGIN
	i := 1; 

	WHILE i <= 10 LOOP 
		RAISE NOTICE '%', i*i;
		i := i + 1;
	END LOOP; 
END; 

$$ language plpgsql

8C

do $$

DECLARE
	a INTEGER;
	b INTEGER;
	i INTEGER;
	temp_n INTEGER;
BEGIN
	a := 0; 
	b := 1;
	i := 1;
	
	WHILE i <= 10 LOOP 
		RAISE NOTICE '%', a;
		temp_n := a;
		a := a + b;
		b := temp_n;
		i := i + 1;
	END LOOP; 
END; 

$$ language plpgsql
