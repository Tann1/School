program mergeArrays;
uses
    sysutils;

type
    arr = array of integer;

var
    array01, array02, array03 : arr;
    count01, count02 : integer;


function input(var count: integer): arr; {purpose is to get user input and return it as an array of integers}
    type
        str_arr = TStringArray;
    var
        input_array : arr;
        input_temp, num : AnsiString;
        temp_array : str_arr;
        idx: integer = 1;

    begin
        SetLength(input_array, 20);     {set input array size to 20}

        WriteLn('Enter elements: ');
        ReadLn(input_temp);
        temp_array := input_temp.split(' '); {split the string by spaces to isolate the integers}

        for num in temp_array do
        begin
            input_array[idx] := StrToInt(num); {convert the string to its corresponding integer value then store it}
            idx := idx + 1;
        end;

        count := idx - 1;   {gives the number of elements; auto updated since passed by reference}
        input := input_array;  {return statement (note the function name assignment is used as return)}
    end; {end of input function}

procedure print(var _array : arr; count : integer);
    var
        str : string = ''; {will hold all the integers as a single string value to print}
        idx : integer;
    
    begin
        for idx := 1 to count - 1 do {don't add the last element due to the space being added}
            str := str + IntToStr(_array[idx]) + ' ';
        str := str + IntToStr(_array[idx + 1]); {add the last element since it's an edge case relative to the spaces being added in the loop above}
        WriteLn(str); 
    end; {end of print function}

procedure merge(var _arr01, _arr02, _arr03: arr; cnt01, cnt02 : integer);
    var
        count03 : integer;
        idx01, idx02, idx03: integer;

    begin
        count03 := cnt01 + cnt02; {size of the merging array}
        SetLength(_arr03, count03); {set the size}
        idx01 := 1; idx02 := 1;

        for idx03 := 1 to count03 do 
        begin
            if (idx01 = cnt01 + 1) or (idx02 = cnt02 + 1) then {meaning we exhausted either of the arrays}
                break;
            if _arr01[idx01] < _arr02[idx02] then {if array 1 current element is smaller than array two element}
            begin
                _arr03[idx03] := _arr01[idx01];
                idx01 := idx01 + 1;               {only increment array 1 element}
            end {end of if}
            else                                  {similar concept for the else statement but this time with array 2}
            begin
                _arr03[idx03] := _arr02[idx02];
                idx02 := idx02 + 1;
            end; {end of else}
        end; {end of loop}

        {consequence of possible exhaustion of either arrays due to the former loop}

        while (idx01 <> cnt01 + 1) do       {only elements from array 1 remain so just put them in the merging array}
        begin
            _arr03[idx03] := _arr01[idx01];
            idx01 := idx01 + 1;
            idx03 := idx03 + 1;      
        end;

        while (idx02 <> cnt02 + 1) do       {only elements from array 2 remains so just put them in the merging array}
        begin
            _arr03[idx03] := _arr02[idx02];
            idx02 := idx02 + 1;
            idx03 := idx03 + 1;      
        end;
    end;    {end of merge function}

begin {start of main program}
    array01 := input(count01);
    array02 := input(count02);
    WriteLn;
    WriteLn('Printing Output');
    print(array01, count01);
    print(array02, count02);
    merge(array01, array02, array03, count01, count02);
    print(array03, count01 + count02);
end. {end of main program}