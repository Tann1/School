program presidents;
uses
    sysutils;

const
    fname = 'presidents.txt'; {file name. change this variable if file name is to be changed}

type
    prezFile = text;
    president = record
        start_year : integer;
        end_year : integer;
        first_name : string;
        middle_initals : string;
        last_name : string;
    end;
    arrPrez = array of president;
   
var
    presidentsArr : arrPrez; {what will be sorted}
    count_of_presidents : integer; {just felt like keep track of the number of presidents}
    searches: array of integer; {will hold the final parsed array of integer for search years}
    searchArray: TStringArray; {will be passed by reference to input function}
    idx, searchSize : integer; {idx for arrPrez type and size for searchArray}
    single_president : president; {a record of a single president}



function input(f_name: string; var count: integer; var _searches: TStringArray) : arrPrez;
    type
        inputArr = TStringArray;
    var
        line : AnsiString;
        line_split : inputArr;
        f : Text; {file variable}
        _result : arrPrez; {return value}
    
    
    begin
        assign(f, f_name);
        reset(f); {set for read}

        SetLength(_result, 20); {allocate memory for the result}
        count := 0;
        while not eof(f) do begin {traverse through the file line by line}
            ReadLn(f, line); {get line in variable f}
            if (line = '-1') then {first sentinel value then break}
                break;  
            line_split := line.split(' '); {split the string by spaces}
            count := count + 1;
            with single_president do begin
                start_year := StrToInt(line_split[0]);
                end_year := StrToInt(line_split[1]);
                first_name := line_split[2];
                if (Length(line_split) = 5) then begin {if string splits into 5 then there is a middle initial}
                    middle_initals := line_split[3];
                    last_name := line_split[4];
                end             
                else begin {other wise only 4 splits so no initals}
                    middle_initals := '';
                    last_name := line_split[3];
                end;
            end; {end of with}
            _result[count - 1] := single_president; {store the result}
        end; {end of while}
        ReadLn(f, line); {get the search aspect of the file}
        close(f); {close since all the data has been extracted}
        line_split := line.split(' '); {split it so the years are split but still need to be converted to integer value}
        searchArray := line_split; {searchArray is passed by reference so it'll auto update the calling program/subroutine}


        input := _result; {return value}
    end; {end of input func}

procedure print_presidents(var presidentsArr: arrPrez; size : integer);

    var
        idx: integer;

    begin
        for idx := 0 to size - 1 do begin
            with presidentsArr[idx] do 
                WriteLn(start_year, ' ', end_year, ' ', first_name, ' ', middle_initals, ' ', last_name);
        end; {end of for}
    end; {end of print_presidents func}

procedure selection_sort(var presidentArr: arrPrez; size: integer); {just a standard O(n^2) selection sort implementation}

    var
        curr_smlx_idx, idx01, idx02: integer;
        temp_president : president;
    
    begin
        for idx01 := 0 to size - 2 do begin
            curr_smlx_idx := idx01;
            for idx02 := curr_smlx_idx + 1 to size - 1 do begin {to find the position of the smallest idx}
                if presidentArr[curr_smlx_idx].start_year >= presidentArr[idx02].start_year then 
                    curr_smlx_idx := idx02;  
            end; {end of inner loop}
            {swap logic}
            temp_president := presidentsArr[idx01];
            presidentsArr[idx01] := presidentsArr[curr_smlx_idx];
            presidentsArr[curr_smlx_idx] := temp_president;
        end; {end of outer loop}
    end;

procedure search_by_years(var presidentArr: arrPrez; var searches : array of integer; sizeOfPresients: integer);
    var
        idx, year: integer;
        found: Boolean = False;
    begin
        for year in searches do begin
            Write('Search year: ', year, ' Found: ');
            for idx:= 0 to sizeOfPresients - 1 do begin
                if (year >= presidentsArr[idx].start_year) and (year < presidentsArr[idx].end_year) then begin
                    found := True;
                    with presidentsArr[idx] do
                        WriteLn(start_year, ' ', end_year, ' ', first_name, ' ', middle_initals, ' ', last_name);
                    break;
                end; {end of if}
            end; {end of inner loop}
            if found = false then
              WriteLn('No Match Found');
            found := false; {reset incase it was true}
        end; {end of outer loop}
    end;

begin
    presidentsArr:= input(fname, count_of_presidents, searchArray); {searchArray is passed by reference so it's implicitly updated through address referencing}
    WriteLn('Input Data Parsed');
    print_presidents(presidentsArr, count_of_presidents);


    searchSize := Length(searchArray) - 1; {ignore the -1 so subtract one from the size}
    SetLength(searches, searchSize); {allocate the proper size for serach}
    
    
    
    WriteLn('All the search years');
    for idx := 0 to searchSize - 1 do begin {populate/initialize searches array}
        if (searchArray[idx] = '-1') then
            break;
        searches[idx] := StrToInt(searchArray[idx]);
        Write(searches[idx], ' ');
    end; {end of for}
    WriteLn; WriteLn;


    WriteLn('Starting the main program');
    WriteLn('Sorting Presidents . . .');
    selection_sort(presidentsArr, count_of_presidents);
    WriteLn('Sorted Presidents list');
    print_presidents(presidentsArr, count_of_presidents);

    WriteLn; WriteLn('Searching for respective presidents . . .');
    WriteLn('Will find a match as long as start year <= search year < end year');
    search_by_years(presidentsArr, searches, count_of_presidents);
end.