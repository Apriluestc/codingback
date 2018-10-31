--查找最晚入职员工的所有信息

select * from employees
where
hire_date = (select max(hire_date) from employees);

--查找入职员工时间排名倒数第三的员工所有信息

select * from employees order by
hire_date desc limit 2,1;

--查找各个部门当前(to_date='9999-01-01')领导当前薪水详情以及其对应部门编号dept_no

select 
salaries.emp_no,
salaries.salary,
salaries.from_date,
salaries.to_date,
dept_manager.dept_no
from salaries inner join dept_manager on
dept_manager.emp_no = salaries.emp_no
and dept_manager.to_date = '9999-01-01'
and salaries.to_date = '9999-01-01';

--查找所有已经分配部门的员工的last_name和first_name

select
employees.last_name,
first_name,
dept_emp.dept_no
from employees inner join dept_emp on
employees.emp_no=dept_emp.emp_no;

--对于表actor批量插入如下数据
'			+---------+-------------+-------------+----------------------+
			| actor_id|	first_name	|  last_name  |    	  last_update    |
			+---------+-------------+-------------+----------------------+
			|	1 	  |	 PENELOPE   |   GUINESS   |	 2006-02-15 12:34:33 |
			+---------+-------------+-------------+----------------------+
			|	2 	  |   NICK 	  	|	WAHLBERG  |	 2006-02-15 12:34:33 |
			+---------+-------------+-------------+----------------------+
'
insert into actor
values
(
    1,
    'PENELOPE',
    'GUINESS',
    '2006-02-15 12:34:33'
),
(
    2,
    'NICK',
    'WAHLBERG',
    '2006-02-15 12:34:33'
);

--找出所有员工当前(to_date='9999-01-01')具体的薪水salary情况，对于相同的薪水只显示一次,并按照逆序显示

select salary from salaries 
where to_date = '9999-01-01'
group by salary
order by salary
desc

--查找最晚入职员工的所有信息
select * from employees 
where hire_date = (select max(hire_date) from employees);

--查找入职员工时间排名倒数第三的员工所有信息
select * from employees
order by hire_date desc limit 2,1;

--查找薪水涨幅超过15次的员工号emp_no以及其对应的涨幅次数t

select emp_no, count(emp_no) from salaries
group by emp_no having t > 15;

--获取所有部门当前manager的当前薪水情况，给出dept_no, emp_no以及salary，当前表示to_date='9999-01-01'
select
dept_manager.dept_no,
salaries.emp_no,
salaries.salary
from dept_manager inner join salaries on
dept_manager.emp_no = salaries.emp_no
and dept_manager.to_date = '9999-01-01'
and salaries.to_date = '9999-01-01';

--从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。

select
title,
count(title) as t
from titles
group by title
having t >= 2;

 















