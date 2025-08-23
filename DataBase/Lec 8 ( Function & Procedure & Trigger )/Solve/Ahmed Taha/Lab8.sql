--SQLServer lab
--Note: Use ITI DB
use ITI ;
--1.Create a scalar function that takes date and returns Month name of that date.
create function dbo.getmonth(@date date)
returns varchar(9)
as begin 
declare @month varchar(10)
select  @month = datename(month,@date);
return @month
end

select  dbo.getmonth('2025-08-20') AS MonthName;
------------------------------------------------------------------------------------------
--2.Create a multi-statements table-valued function that takes 2 integers and returns the Even values between them.
create function even(@num1 int,@num2 int)
returns @t table (Number int)
as begin
while @num1 <= @num2
begin
	if @num1 % 2 =0
	begin 
	insert into @t values(@num1)
	end
set @num1 +=1
end
return
end

select * from even(3,15)
---------------------------------------------------------------------------------------
--3.Create inline function that takes Student No and returns Department Name with Student full name.
create function StudentName_Dept(@St_No int)
returns table
as
return 
(
select CONCAT(St_Fname,' ',St_Lname) [Full Name] ,
Dept_Id from Student
where St_Id = @St_No
)

select * from StudentName_Dept(10)
-----------------------------------------------------------------------------------------------------
--4.Create a scalar function that takes Student ID and returns a message to user 
--a.If first name and Last name are null then display 'First name & last name are null'
--b.If First name is null then display 'first name is null'
--c.If Last name is null then display 'last name is null'
--d.Else display 'First name & last name are not null'
create function message_to_user(@ID int)
returns varchar(50)
as 
begin 
declare @fname varchar(50)
declare @lname varchar(50)
declare @message varchar(100)

set @fname = (select St_Fname from Student where St_Id = @ID)
set @lname = (select St_Lname from Student where St_Id = @ID)

if @fname is null and @lname is null
set @message = 'First name & last name are null'

else if @fname is null
set @message = 'First name is null'

else if @lname is null
set @message =  'Last name is null'

else if @fname is not null and @lname is not null
set @message =  'First name & last name are not null'

return @message 
end

select dbo.message_to_user(11)


--5.Create inline function that takes integer which represents manager ID and displays department name, Manager Name and hiring date 
create function mng(@MngID int)
returns table 
as
return 
(
select d.dept_name, i.ins_name, d.manager_hiredate
from Instructor i join Department d
on i.Ins_Id=d.Dept_Manager
where d.Dept_Manager=@MngID 
)

select * from mng(123)
--------------------------------------------------------------------------------
--6.Create multi-statements table-valued function that takes a string
--If string='first name' returns student first name
--If string='last name' returns student last name 
--If string='full name' returns Full Name from student table 
--Note: Use “ISNULL” function

create function stName(@stringg varchar(10))
returns @t table
(id int,
name varchar(20))
as
begin
if @stringg='first name'
   insert into @t
   select st_id,st_fname from Student
else if @stringg='last name'
   insert into @t
   select st_id,st_lname from Student
else if @stringg='full name'
   insert into @t
   select st_id,st_fname+' '+st_lname from Student
return
end
select * from stname('full name')