--SQLServer Lab
--Note: Use ITI DB
--1.Create a view that displays student full name, course name if the student has a grade more than 50. 
create view St_Course_More50 as
select CONCAT(St_Fname,' ',St_Lname) as [Full Name],
c.Crs_Name
from Student s join Stud_Course sc
on sc.St_Id = s.St_Id
join Course c
on c.Crs_Id = sc.Crs_Id
where sc.Grade > 50

select * from St_Course_More50
----------------------------------------------------------------------------------------------------
--2.Create an Encrypted view that displays manager names and the topics they teach. 
create view Mang_Topic_vw 
with encryption as
select ins.Ins_Name,c.Crs_Name from Instructor ins 
join Department dept
on dept.Dept_Manager = ins.Dept_Id
join Ins_Course ins_co
on ins_co.Ins_Id = ins.Ins_Id
join Course c
on c.Crs_Id = ins_co.Crs_Id

select * from Mang_Topic_vw
----------------------------------------------------------------------------------------------------
--3.Create a view that will display Instructor Name, Department Name for the ‘SD’ or ‘Java’ Department 
create view Inst_Dept as
select inst.Ins_Name,dept.Dept_Name from Instructor inst 
join Department dept 
on dept.Dept_Id = inst.Dept_Id
where dept.Dept_Name in ('SD','Java')

select * from Inst_Dept
----------------------------------------------------------------------------------------------------
--4.Create a view “V1” that displays student data for student who lives in Alex or Cairo. 
--Note: Prevent the users to run the following query 
--Update V1 set st_address=’tanta’
--Where st_address=’alex’;
create view v1 as 
select * from Student
where St_Address in ('Alex','Cairo')
with check option

Update v1 set st_address='tanta'
Where st_address='alex'
--The attempted insert or update failed
----------------------------------------------------------------------------------------------------
--5.Create a view that will display the project name and the number of employees work on it. “Use Company DB”
create view Proj_#Emp_vw as
select p.Pname,COUNT(e.SSN) "Num Employee" 
from Project p
join Works_for w 
on w.Pno = p.Pnumber
join Employee e
on e.SSN = w.ESSn
group by Pname

select * from Proj_#Emp_vw
----------------------------------------------------------------------------------------------------
--6.Create index on column (Hiredate) that allow u to cluster the data in table Department. What will happen?
create clustered index indx_dept_hiredate 
on Departments([MGRStart Date])
--error => عشان  بيطبق علي عمود و بيرتبه و بيكون في الجدولcluster واحد بس و التاريخ ممكن يتكرر وممكن تكون قيم فاضيه
----------------------------------------------------------------------------------------------------
--7.Create index that allow u to enter unique ages in student table. What will happen?
select * from Student
create unique index st_indx 
on Student(St_Age)
-- error => unique index لان العمر هتكرر و بتالي مش هينفع هنا 
-------------------------------------------------------------------------------
