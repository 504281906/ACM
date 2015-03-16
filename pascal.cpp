 begin
  fopen;
  p:=1;q:=0;
  readln(n);
  for i:=1 to n do
    begin
    readln(x);
    if x>0 then
      begin
      dec(p);
      a[p]:=x;
    end;
    if x=0 then
      if (q-p<=1000000) and (q>=p) then
        begin
        for j:=1 to q-p+1 do
          a[q+j]:=a[p+j-1];
        q:=q+q-p+1;
      end;
    if x<0 then
      if q>=p then
        begin
        writeln(a[p]);
        inc(p);
      end;
