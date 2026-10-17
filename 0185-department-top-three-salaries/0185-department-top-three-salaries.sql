# Write your MySQL query statement below
# Write your MySQL query statement below
with emp as(select e.id, e.name as Employee ,e.salary,e.departmentId,d.name as Department,
DENSE_RANK() over(partition by e.departmentId order by e.salary desc) as salary_rank
 from Employee as e
join Department as d on  e.departmentId = d.id )


 select Department,Employee, salary as Salary from emp where salary_rank <=3 ;