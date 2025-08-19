﻿--1.Retrieve number of students who have a value in their age. 
select count(St_Age) "Num Students" 
from Student

--2.Get all instructors Names without repetition
select distinct Ins_Name 
from Instructor

--3.Display student with the following Format (use isNull function) 
--Student ID	Student Full Name	Department name --concat()
select St_Id,
isnull(St_Fname,'')+' '+isnull(St_Lname,'') "Full Name",
d.Dept_Name
from Student s join Department d
on d.Dept_Id = s.Dept_Id

--4.Display instructor Name and Department Name 
--Note: display all the instructors if they are attached to a department or not
select Ins_Name,Dept_Name 
from Instructor ins left join Department d
on d.Dept_Id = ins.Dept_Id

--5.Display student full name and the name of the course he is taking
--For only courses which have a grade  
select concat(St_Fname,' ',St_Lname) "Full Name", 
Crs_Name
from Student s join Stud_Course st
on st.St_Id = s.St_Id 
join Course c
on c.Crs_Id = st.Crs_Id 
where st.Grade is not null

--6.Display number of courses for each topic name
select t.Top_Name,count(c.Crs_Id) "Num Courses" 
from Topic t join Course c
on c.Top_Id = t.Top_Id
group by t.Top_Name

--7.Display max and min salary for instructors
select 
max(Salary) "Max Salary", 
min(Salary) "Min Salary" 
from Instructor

--8.Display instructors who have salaries less than the average salary of all instructors.
select * from Instructor 
where Salary < (select AVG(Salary) from Instructor)

--9.Display the Department name that contains the instructor who receives the minimum salary.
select distinct Dept_Name 
from Department d join Instructor inst 
on inst.Dept_Id = d.Dept_Id 
where inst.Salary = (select min(Salary) from Instructor)

--10.Select max two salaries in instructor table. 
select top 2 salary 
from Instructor
order by Salary desc

--11.Select instructor name and his salary but if there is no salary display instructor bonus. “use one of coalesce Function”
select Ins_Name,
coalesce(convert(varchar(8),Salary),'bouns') as Salaries
from Instructor

--12.Select Average Salary for instructors 
select avg(ISNULL(Salary,0)) as [Avg Salary]
from Instructor

--13.Select Student first name and the data of his supervisor 
select st.St_Fname,super.* from 
Student st join Student super
on super.St_Id = st.St_super

--14.Write a query to select the highest two salaries in Each Department for instructors who have salaries.
--“using one of Ranking Functions”
select * from
(select  Dept_Name, 
Salary,
RANK() over(partition by dept_name order by salary desc) as R
from Instructor ins join Department d
on d.Dept_Id = ins.Dept_Id
where ins.Salary is not null) as t
where R <=2

--15.Write a query to select a random  student from each department.  “using one of Ranking Functions”
select * from(
select St_Id,Dept_Id,St_Fname,
row_number()over(partition by dept_id order by newid()) as rn
from Student
) random_st
where rn=1

-------------------------------------------------------------------------------------------------------

--Part-2: Use AdventureWorks DB
--1.Display the SalesOrderID, ShipDate of the SalesOrderHeader table (Sales schema) to show SalesOrders 
--that occurred within the period ‘7/28/2002’ and ‘7/29/2014’
select SalesOrderID,ShipDate,OrderDate
from Sales.SalesOrderHeader
where OrderDate between '7/28/2002' and '7/29/2014'

--2.Display only Products(Production schema) with a StandardCost below $110.00 
--(show ProductID, Name only)
select ProductID,Name
from Production.Product
where StandardCost < 110

--3.Display ProductID, Name if its weight is unknown
select ProductID,Name,Weight
from Production.Product
where Weight is null

--4.Display all Products with a Silver, Black, or Red Color
select *
from Production.Product
where Color in ('Silver','Black','Red')

--5.Display any Product with a Name starting with the letter B
select *
from Production.Product
where Name like 'B%'

--6.Run the following Query
--Then write a query that displays any Product description with underscore value in its description.
UPDATE Production.ProductDescription
SET Description = 'Chromoly steel_High of defects'
WHERE ProductDescriptionID = 3

select Description 
from Production.ProductDescription
where Description like '%[_]%'

--7.Calculate sum of TotalDue for each OrderDate in Sales.SalesOrderHeader table
--for the period between  '7/1/2001' and '7/31/2014'
select sum(TotalDue) "Total Due",OrderDate 
from Sales.SalesOrderHeader
group by OrderDate
having OrderDate between '7/1/2001' and '7/31/2014'

--8.Display the Employees HireDate (note no repeated values are allowed)
select distinct HireDate 
from HumanResources.Employee

--9.Calculate the average of the unique ListPrices in the Product table
select avg(distinct isnull(ListPrice,0)) 
from Production.Product

--10.Display the Product Name and its ListPrice within the values of 100 and 120 
--the list should has the following format "The [product name] is only! [List price]" 
--(the list will be sorted according to its ListPrice value)
select Name,ListPrice,
CONCAT('The ',Name,' is only! ',ListPrice) from Production.Product
where ListPrice between 100 and 120

--11.	
--a) Transfer the rowguid ,Name, SalesPersonID, Demographics from Sales.Store table in a newly created table named [store_Archive]
--Note: Check your database to see the new table and how many rows in it?
select rowguid,Name,SalesPersonID,Demographics 
into store_Archive
from Sales.Store 

select * from store_Archive

--b)Try the previous query but without transferring the data? 
select rowguid,Name,SalesPersonID,Demographics 
into store_Archive2
from Sales.Store 
where 1=0 --=>  شرط مستحيل الحدوث


--12.Using union statement, retrieve the today’s date in different styles using convert or format funtion.
select convert(char(10),getdate(),101) as Today
union
select convert(char(10),getdate(),103)   
union
select convert(char(10),getdate(),105);


