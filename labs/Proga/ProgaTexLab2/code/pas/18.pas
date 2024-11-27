var
    n, i, newSize, cnt, sum, evenCnt: integer;
    arr: array of integer;
    newArr: array of integer;
begin
    readln(n);
    SetLength(arr, n);

    newSize := n + 2;
    SetLength(newArr, newSize);

    cnt := 0;
    sum := 0;
    evenCnt := 0;

    for i := 0 to n - 1 do begin
        read(arr[i]);
        if (arr[i] mod 3 = 0) then 
            cnt := cnt + 1;

        if (arr[i] mod 2 = 0) then begin
            sum := sum + arr[i];
            evenCnt := evenCnt + 1;
        end;
    end;

    newArr[0] := cnt;

    if evenCnt > 0 then
        newArr[newSize - 1] := round(sum div evenCnt)
    else
        newArr[newSize - 1] := 0;

    for i := 1 to newSize - 2 do begin
        newArr[i] := arr[i - 1];
    end;

    for i := 0 to newSize - 1 do begin
        write(newArr[i]);
        if i < newSize - 1 then
            write(' ');
    end;
end.
