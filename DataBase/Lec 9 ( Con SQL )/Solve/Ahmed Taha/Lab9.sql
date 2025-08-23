--1.
declare emp_crsr cursor
for
    select salary
    from employee
    for update;

declare @empsalary int;

open emp_crsr;

fetch next from emp_crsr into @empsalary;

while @@fetch_status = 0
begin
    if @empsalary < 3000
    begin
        update employee
        set salary = @empsalary * 1.10
        where current of emp_crsr;
    end
    else
    begin
        update employee
        set salary = @empsalary * 1.20
        where current of emp_crsr;
    end;

    fetch next from emp_crsr into @empsalary;
end;

close emp_crsr;
deallocate emp_crsr;

--2.
declare dept_name_crsr cursor
for
    select d.dname, e.fname
    from department d
    join employee e
        on d.mgrssn = e.ssn
    for read only;

declare @deptname varchar(50), @mgrname varchar(50);

open dept_name_crsr;

fetch next from dept_name_crsr into @deptname, @mgrname;

while @@fetch_status = 0
begin
    print @deptname + ' - ' + @mgrname;

    fetch next from dept_name_crsr into @deptname, @mgrname;
end;

close dept_name_crsr;
deallocate dept_name_crsr;

--3.try to display all students first name in one cell separated by comma. using cursor 
declare student_fname_crsr cursor
for
    select st_fname
    from student
    where st_fname is not null
    for read only;

declare @names varchar(max) = '', @fname varchar(100);

open student_fname_crsr;

fetch next from student_fname_crsr into @fname;

while @@fetch_status = 0
begin
    set @names = case when @names = '' then @fname else @names + ',' + @fname end;
    fetch next from student_fname_crsr into @fname;
end;

close student_fname_crsr;
deallocate student_fname_crsr;

select @names as allstudentnames;

--4.
-- full backup
backup database sd to disk = 'd:\sql labs\sd_full.bak' with init;

-- differential backup
backup database sd to disk = 'd:\sql labs\sd_diff.bak' with differential;

--5.
create table stu (id int, name varchar(20));

bulk insert stu
from 'd:\sql labs\bultexcel.csv'
with (
    fieldterminator = ',',
    rowterminator = '\n',
    firstrow = 2
);

--6.try to generate script from db iti that describes all tables and views in this db
select syt.name as tablename, syv.name as viewname
from sys.tables syt
join sys.all_views syv
    on syt.object_id = syv.object_id
where syv.is_ms_shipped = 0;



-- Part2: What is the difference between the following objects in SQL Server

--1. batch: group of statements executed together
--   script: file with one or more batches
--   transaction: unit of work all succeed or all fail

--2. trigger: runs automatically on insert/update/delete
--   stored procedure: runs only when called

--3. stored procedure: may return data or not, can use dml
--   function: always returns value, limited dml

--4. drop: removes table completely
--   truncate: remove all rows, faster, no where
--   delete: remove rows with condition

--5. select: get data
--   select into: create new table with data

--6. local variable: defined inside batch/sp
--   global variable: system provided (@@var)

--7. cast: standard conversion
--   convert: sql server specific, supports styles

--8. ddl: create/alter/drop
--   dml: insert/update/delete
--   dcl: grant/revoke
--   dql: select
--   tcl: commit/rollback/savepoint

--9. for xml raw: each row as <row>
--   for xml auto: builds xml using table names

--10. inline tvf: returns result from one query
--    multi-statement tvf: returns table with multiple steps

--11. varchar(50): up to 50 chars
--    varchar(max): up to 2gb

--12. datetime(3): 3 decimal seconds
--    datetime2(7): higher precision
--    datetimeoffset(7): with timezone

--13. default instance: no name needed
--    named instance: must specify name

--14. sql auth: login with username/password
--    windows auth: uses windows account

--15. clustered index: sorts data physically
--    non-clustered index: separate structure with pointer

--16. rollup: subtotals in hierarchy
--    cube: all possible subtotals

--17. identity: tied to one table
--    sequence: independent object, reusable

--18. inline function: accepts parameters, returns table
--    view: no parameters, like saved query

--19. table variable: stored in memory, small data
--    temp table: stored in tempdb, big data

--20. row_number(): unique sequence no gaps
--    dense_rank(): same rank for ties, no gaps
