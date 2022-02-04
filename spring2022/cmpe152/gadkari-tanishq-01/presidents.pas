program presidents;
uses
    sysutils;

const
    fname = 'presidents.txt';

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
    presidentsArr : arrPrez;
    count_of_presidents : integer;
    searches: array of integer;
    searchArray: TStringArray;
    temp_string: AnsiString;
    idx, searchSize : integer;
    single_president : president;



function input(f_name: string; var count: integer; var _searches: TStringArray) : arrPrez;
    type
        inputArr = TStringArray;
    var
        line : AnsiString;
        line_split : inputArr;
        f : Text; {file variable}
        _result : arrPrez;
    
    
    begin
        assign(f, f_name);
        reset(f);

        SetLength(_result, 20);
        count := 0;
        while not eof(f) do begin
            ReadLn(f, line);
            if (line = '-1') then
                break;  
            line_split := line.split(' ');
            count := count + 1;
            with single_president do begin
                start_year := StrToInt(line_split[0]);
                end_year := StrToInt(line_split[1]);
                first_name := line_split[2];
                if (Length(line_split) = 5) then begin
                    middle_initals := line_split[3];
                    last_name := line_split[4];
                end             
                else begin
                    middle_initals := '';
                    last_name := line_split[3];
                end;
            end;
            _result[count - 1] := single_president;
        end;
        ReadLn(f, line);
        close(f);
        line_split := line.split(' ');
        searchArray := line_split;


        input := _result;
    end;



begin
    presidentsArr:= input(fname, count_of_presidents, searchArray);

    searchSize := Length(searchArray) - 1; {ignore the -1 so subtract one from the size}
    SetLength(searches, searchSize);
    WriteLn('All the search years');
    for idx := 0 to searchSize - 1 do begin
        if (searchArray[idx] = '-1') then
            break;
        searches[idx] := StrToInt(searchArray[idx]);
        Write(searches[idx], ' ');
    end;
    WriteLn; WriteLn;

    WriteLn('Input Data Parsed');
    for idx := 0 to count_of_presidents - 1 do begin
        with presidentsArr[idx] do begin
            WriteLn(start_year, ' ', end_year, ' ', first_name, ' ', middle_initals, ' ', last_name);
        end;
    end;

    WriteLn;

end.