--                                                            Lab 4
--SQL

--1.For each project, list the project name and the total hours per week (for all employees) spent on that project.
select Pname,SUM(Hours) as Hours 
from Project p join Works_for w
on w.Pno = p.Pnumber
group by Pname

--2.Display the data of the department which has the smallest employee ID over all employees' ID.
--select SSN from Employee
--order by ssn asc

select d.* from Departments d 
join Employee e
on e.Dno = d.Dnum
where e.SSN = (select min(SSN) from Employee) --112233

--3.For each department, retrieve the department name and the maximum, minimum and average salary of its employees.
select Dname, max(Salary) [Max Salary],min(Salary) [Min Salary],avg(Salary) [AVG Salary] 
from Employee e join Departments d
on d.Dnum = e.Dno
group by Dname

--4.For each department-- if its average salary is less than the average salary of all employees
-- display its number, name and number of its employees.
select Dname,Dnum,count(SSN) as "#Emp"
from Employee e join Departments d
on d.Dnum = e.Dno
group by Dname,Dnum
having avg(Salary) < (select avg(Salary) from Employee)

--5.Try to get the max 2 salaries (using subquery - bonus)
--select top 2 Salary from Employee 
--order by Salary desc

select Salary from Employee 
where Salary in (select top 2 Salary 
from Employee order by Salary desc)


--6.Get the full name of employees that is similar to any dependent name
select distinct e.Fname+' '+e.Lname as [full name] 
from  Employee e join Dependent d
on d.ESSN = e.SSN
where d.Dependent_name like CONCAT('%',e.Fname,'%') and 
d.Dependent_name like CONCAT('%',e.Lname,'%')

--7.Insert your personal data to the employee table as a new employee in department number 30,
--SSN = 102672, Superssn = 112233, salary=3000.**
insert into Employee(Dno,SSN,Superssn,Salary,Fname,Lname)
values(30,102672,112233,3000,'ahmed','taha')

--8.Insert another employee with personal data your friend as new employee in department number 30,
--SSN = 102660, but don’t enter any value for salary or supervisor number to him.
insert into Employee(Dno,SSN)
values(30,102660)

--9.Upgrade your salary by 20 % of its last value.
update Employee 
set Salary = Salary + Salary * 0.20 
where SSN = 102672

--10.In the department table insert new department called "DEPT IT" , 
--with id 100, employee with SSN = 112233 as a manager for this department. The start date for this manager is '1-11-2006'
insert into Departments (Dname,Dnum,MGRSSN,[MGRStart Date])
values('DEPT IT',100,112233,'1-11-2006')

--11.Do what is required if you know that : Mrs.Noha Mohamed(SSN=968574) *********
--moved to be the manager of the new department (id = 100),
--and they give you(your SSN =102672) her position (Dept. 20 manager) 

--a.First try to update her record in the department table
update Departments 
set MGRSSN = 968574
where Dnum = 100;

--b.Update your record to be department 20 manager.
update Departments 
set MGRSSN = 102672
where Dnum = 20;

--c.Update the data of employee number=102660 to be in your teamwork (he will be supervised by you) (your SSN =102672)
update Employee 
set Superssn = 102672
where SSN = 102660

--12.Unfortunately the company ended the contract with Mr. Kamel Mohamed (SSN=223344) 
--so try to delete his data from your database
--in case you know that you will be temporarily in his position.
--Hint: (Check if Mr. Kamel has dependents, works as a department manager, 
--supervises any employees or works in any projects and handle these cases).

--SSN=223344,myssn=102672,dno = 10
--select * from Employee e join Dependent d
--on d.ESSN = e.SSN
--where SSN = 223344

--update dept manager
update Departments 
set MGRSSN = 102672
where MGRSSN = 223344

update Employee
set Superssn = 102672
where Superssn = 223344

delete Dependent
where ESSN = 223344

update Works_for
set ESSn = 102672
where ESSN = 223344

delete Employee 
where SSN = 223344

--13.Try to update all salaries of employees who work in Project ‘Al Rabwah’ by 30%
update Employee 
set Salary = Salary + Salary * 0.30
from Employee e join Works_for w
on w.ESSn = e.SSN 
join Project p 
on p.Pnumber = w.Pno
where p.Pname = 'Al Rabwah'

--14.Display the employee number and name if at least one of them have dependents (use exists keyword) 
select SSN,CONCAT(Fname,' ',Lname) as [Full Name] 
from Employee e
where exists(
select SSN 
from Employee e join Dependent d
on d.ESSN = e.SSN)


--15.Retrieve a list of employees names and the projects names they are working on 
--ordered by department number and within each department, ordered alphabetically by last name, first name.

select CONCAT(Fname,' ',Lname) as [Full Name],p.Pname 
from Employee e 
join Works_for w
on w.ESSn = e.SSN
join Project p 
on p.Pnumber = w.Pno
order by e.Dno,e.Lname,e.Fname

