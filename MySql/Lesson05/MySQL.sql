--查找当前薪水(to_date='9999-01-01')排名第二多的员工编号emp_no、薪水salary、last_name以及first_name，不准使用order by

select
salaries.emp_no,
max(salary) as salary,
employees.last_name,
employees.first_name
from salaries
inner join employees on
salaries.emp_no = employees.emp_no
where salaries.to_date = '9999-01-01'
and salaries.salary not in (select max(salaries.salary) from salaries);

