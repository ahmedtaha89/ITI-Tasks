--Lab3
--SQL
--Ahmed Taha

--Try to create the following Queries:

--1.Display the Department id, name and id and the name of its manager.
select Dnum,Dname,e.Fname+' '+Lname as name,SSN from  Departments d join Employee e
on e.SSN = d.MGRSSN

--2.Display the name of the departments and the name of the projects under its control.
select d.Dname , p.Pname from Departments d join Project p
on p.Dnum = d.Dnum

--3.Display the full data about all the dependence associated with the name of the employee they depend on him/her.
select d.*, e.Fname+' '+e.Lname as EmpName from Dependent d join Employee e
on e.SSN = d.ESSN

--4.Display the Id, name and location of the projects in Cairo or Alex city.
select Pnumber,Pname, Plocation from Project 
where City in ('Cairo','Alex')

--5.Display the Projects full data of the projects with a name starts with "a" letter.
select * from Project 
where Pname like  'a%'

--6.display all the employees in department 30 whose salary from 1000 to 2000 LE monthly
select * from Employee 
where Dno = 30 and Salary between 1000 and 2000

--7.Retrieve the names of all employees in department 10 who works more than or equal10 hours per week on "AL Rabwah" project.
select e.Fname+' '+e.Lname as EmpName from Employee e join Works_for w
on w.ESSn = e.SSN
join  Project p 
on p.Pnumber = w.Pno
where Dno = 10  and w.Hours >= 10 and p.Pname like '%AL Rabwah%'

--8.Find the names of the employees who directly supervised with Kamel Mohamed.
select emp.Fname+' '+emp.Lname as EmpName from Employee emp join Employee mng
on mng.SSN = emp.Superssn
where mng.Fname+' '+ mng.Lname = 'Kamel Mohamed'

--9.Retrieve the names of all employees and the names of the projects they are working on, sorted by the project name.
select e.Fname+' '+e.Lname as EmpName, p.Pname from Employee e join Works_for w
on w.ESSn = e.SSN
join Project p
on p.Pnumber = w.Pno
order by p.Pname asc

--10.Display the employees names and their departments’ names and even if they do not have departments
select e.Fname+' '+e.Lname as EmpName , d.Dname from Employee e left outer join Departments d
on d.Dnum = e.Dno

--11.For each project located in Cairo City , find the project number, the controlling department name ,
--the department manager last name ,address and birthdate.
select p.Pnumber,d.Dname,e.Lname,e.Address,e.Bdate from Project p join Departments d
on d.Dnum = p.Dnum 
join Employee e
on e.SSN = d.MGRSSN
where p.City = 'Cairo'

--12.Display All Data of the managers
select distinct mng.* from Employee emp join Employee mng
on mng.SSN = emp.Superssn -- 7rows => 3repeted

--13.Display (Using Union Function)
--a.The name and the gender of the dependence that's gender is Female and depending on Female Employee.
select Dependent_name as FemaleName,Sex from Dependent where Sex like '%F%'
union select Fname+' '+Lname,Sex from Employee where Sex like '%F%'
union all
--b.And the male dependence that depends on Male Employee.
select Dependent_name as MaleName,Sex from Dependent where Sex like '%M%'
union select Fname+' '+Lname,Sex from Employee where Sex like '%M%'

--14.Get the names of employees that is similar to any dependent name (using Intersect)
select Fname+' '+Lname as FullName from Employee
intersect 
select Dependent_name from Dependent
--- Not Return

--15.Display departments that have employees don’t have dependents 
-- كل الموظيفن اللي مش ليهم قرايب
select * from Employee e left outer join Dependent dep
on dep.ESSN = e.SSN
where ESSN is null -- 4rows

select distinct d.* 
from Employee e 
left outer join Dependent dep
on dep.ESSN = e.SSN
join Departments d 
on d.Dnum = e.Dno 
WHERE dep.ESSN IS NULL;

-- 15. Display department numbers and names that have no employees with dependents
select d.* from Departments d
except
select d.* from Employee e
join Dependent dep
on e.SSN = dep.ESSN
join Departments d
on e.Dno = d.Dnum;