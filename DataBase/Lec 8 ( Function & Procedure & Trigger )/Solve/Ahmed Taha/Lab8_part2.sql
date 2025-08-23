--1
use iti
create proc stnum
as
select d.dept_name,count(s.st_id) as numofstudents
from department d join student s
on d.dept_id=s.dept_id
group by d.dept_name
stnum

--2
use sd
create proc empcountp1
as
declare @empcount int
select @empcount=count(*) from works_on where projectno=1
if @empcount>=3
begin
select 'the number of employees in the project p1 is '+cast(@empcount as varchar(10))
end
else
begin
select 'the following employees work for the project p1'
union all
select (e.empfname+' '+e.emplname) as fullname
from humanresource.employee e join works_on w on e.empno=w.empno
join company.project p on w.projectno=p.projectno
where p.projectno=1
end
empcountp1

--3
create proc transferpj @old int,@new int,@pjno int
as
update works_on
set empno=@new
from humanresource.employee join works_on
on humanresource.employee.empno=works_on.empno
where works_on.empno=@old and projectno=@pjno
transferpj 2581,28559,3

--4
create table audit(pjno int,username varchar(20),modifieddate date,oldbudget int,newbudget int)
create trigger t1
on company.project
after update
as
if update(budget)
begin
declare @new int,@old int,@pj int
select @old=budget from deleted
select @new=budget from inserted
select @pj=projectno from company.project where budget=@new
insert into audit values(@pj,suser_name(),getdate(),@old,@new)
end
update company.project set budget=90000 where projectno=2

--5
use iti
create trigger t1
on department
instead of insert
as
select 'can’t insert a new record in that table'
insert into department(dept_id,dept_location) values(777,'jhv')

--6
use sd
create trigger t1
on humanresource.employee
after insert
as
if format(getdate(),'mmmm')='march'
begin
select 'cant insert'
rollback
end

--7
use iti
create table studentaudit(username varchar(128),date date,notes varchar(128))
alter trigger t2
on student
after insert
as
begin
declare @username nvarchar(128)=system_user
declare @key int,@note varchar(128),@tableename varchar(20)='student'
select @key=st_id from inserted
set @note=@username+'insert new row with key='+cast(@key as varchar(10))+' in table '+@tableename
insert into studentaudit values(@username,getdate(),@note)
end
insert into student(st_id,st_fname,st_lname,st_age) values(15,'john','wick',21)
select * from studentaudit

--8
create trigger t3
on student
instead of delete
as
begin
declare @username nvarchar(128)=system_user
declare @note varchar(128)
declare @key int
select @key=st_id from deleted
set @note='try to delete row with key='+cast(@key as varchar(10))
insert into studentaudit values(@username,getdate(),@note)
end
delete from student where st_id=15
select * from studentaudit
