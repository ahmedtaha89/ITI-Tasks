create database Day6;
-- 1)
create table Department(
DeptNo int primary key,
DeptName varchar(50),
Location varchar(50))

create rule Location_R as @value in ('NY','DS','KW')

sp_bindrule Location_R, 'Department.Location'

insert into Department
values(1,'Research','NY'),
	  (2,'Accounting','DS')

-------------------------------------------------
-- 2)
create table Employee(
EmpNo int primary key,
Emp_Fname varchar(50) not null,
Emp_lname varchar(50) not null,
Salary float unique,
DeptNo int foreign key references department(deptno))

create rule Salary_R as @v < 6000
sp_bindrule Salary_R , 'Employee.Salary'

insert into Employee values
(123,'Mathew','Smith',2500,1),
(124,'Ann','Jones',3000,2),
(10102,'Ann','Jones',4000,2)

----------------------------------------------------
-- 3)
create table Project(
ProjectNo varchar(10) primary key,
ProjectName	varchar(50) not null,
Budget int)

insert into Project values
('p1','Apollo',120000),
('p2','Gemini',95000),
('p3','Artemis',150000)

-----------------------------------------------------
-- 4)
create table Works_on (
    EmpNo int not null, 
    ProjectNo varchar(10) not null,
    Job varchar(50) null,
    Enter_Date date not null default (getdate()),
    constraint PK_WorksOn primary key (EmpNo, ProjectNo),
    constraint FK_WorksOn_Emp foreign key (EmpNo) references Employee(EmpNo),
    constraint FK_WorksOn_Project foreign key (ProjectNo) references Project(ProjectNo))

 insert into Works_on values
(123,'p1','Analyst','2006-10-01'),
(124,'p3','Manager','2012-01-01')
-----------------------------------------------------
-- 5) Testing Referential Integrity
-- 1-
insert into Works_on(EmpNo)
values(11111)
-- Cannot insert the value NULL into column 'ProjectNo'

-- 2-
update Works_on 
set EmpNo = 11111 
where EmpNo = 10102  
-- (0 rows affected)

-- 3-
update Employee
set EmpNo = 22222
where EmpNo = 10102
-- مرتبط بجدول تاني مش هنبفع يعدل

-- 4-
delete Employee
where EmpNo = 10102
--  نفس الكلام مرتبط بجدول تاني مش هنبفع يمسح 
-----------------------------------------------------


-- 6) Table modification
-- 1-Add TelephoneNumber column to the employee table[programmatically]
alter table Employee
add phone varchar(14);

-- 2-drop this column[programmatically]
alter table Employee
drop column phone;

-- 3-Bulid A diagram to show Relations between tables
-- Done

-----------------------------------------------------
--2.Create the following schema and transfer the following tables to it 
--a.Company Schema 
create schema Company
--i.Department table (Programmatically)
--ii.Project table (using wizard)
alter schema Company transfer dbo.Department

--b.Human Resource Schema
--i.Employee table (Programmatically)
create schema [Human Resource]
alter schema [Human Resource] transfer dbo.Employee
-----------------------------------------------------------------------------------------
--3.Write query to display the constraints for the Employee table.
select 
info_cons.constraint_name,
info_cons_col.column_name
from information_schema.table_constraints info_cons
join information_schema.constraint_column_usage info_cons_col
on info_cons.constraint_name = info_cons_col.constraint_name
where info_cons.table_name = 'Employee';
-----------------------------------------------------------------------------------------
--4.Create Synonym for table Employee as Emp and then run the following queries and describe the results
create synonym Emp for [Human Resource].Employee

Select * from Employee
--Invalid object name 'Employee'. =>  schema محتاج اسم 
Select * from [Human Resource].Employee -- => رجعت كل الداتا تمام 
Select * from Emp --=> رجعت كل الداتا تمام
Select * from [Human Resource].Emp -- => Emp مش هرجع حاجه عشان مفيش جدول اسمه 
-----------------------------------------------------------------------------------------
--5.Increase the budget of the project where the manager number is 10102 by 10%.
update cp
set Budget = Budget+Budget*0.10
from Company.Project cp join Works_on w
on w.ProjectNo = cp.ProjectNo
join [Human Resource].Employee as e 
on e.EmpNo = w.EmpNo
where e.EmpNo = 10102 and w.Job = 'Manager'
-- (1 row affected)

--6.Change the name of the department for which the employee named James works.The new department name is Sales.
select * from  [Human Resource].Employee 

update Company.Department
set DeptName = 'Sales'
from Company.Department d
 join [Human Resource].Employee e
 on e.DeptNo = d.DeptNo
 where e.Emp_Fname = 'James'

--7.Change the enter date for the projects for those employees who work in project p1 and belong to department ‘Sales’. 
--The new date is 12.12.2007.
update Works_On
set Enter_Date='12.12.2007'
from Works_On w join  [Human Resource].EMPLOYEE e
on w.EmpNo=e.EmpNo
join Company.DEPARTMENT d 
on e.DeptNo=d.DeptNo
where ProjectNo='p1' and DeptName='Sales'

--8.Delete the information in the works_on table for all employees who work for the department located in KW.
delete from Works_On
from Works_On w join [Human Resource].EMPLOYEE e
on w.EmpNo=e.EmpNo
join Company.DEPARTMENT d 
on e.DeptNo=d.DeptNo
where Location='KW'