--创建数据库 sell
create database sell charset = utf8;

--创建 goods 表
create table goods(
    id int unsigned primary key,
    goods_name varchar(50) not null default '', 
    price float not null default 0.0 
);

--插入五条记录
insert into goods values(101, '牛排', 100.8), (102, '鸡排', 27.9), (103, '披萨', 27.5), (104, '面条', 12.5), (105, '小面', 10.8);

--将所有的价格都改为 300 
update goods set price=300;

--将 id = 101  的商品价格改为 1000
update goods set price=1000 where id=101;

--将 id = 101 的商品价格增加 200 块
update goods set price=price+200 where id=102;

--删除 id = 101 的数据
delete from goods where id=101;
--复制表 goods 的结构与数据到表 goods2
create table goods2 like goods;
insert into goods2 select * from goods;
--分别使用 delete from 与 truncate 清空表 goods、goods2
delete from goods;
truncate table goods;

--创建学生表
create table student (
    id int not null default 1,
    name varchar(20) not null default '',
    chinese float not null default 0.0 comment '语文成绩',  
    english float not null default 0.0 comment '英语成绩',  
    math float not null default 0.0 comment '数学成绩'
);

--插入数据
insert into student values(1, '猪八戒', 89, 78, 90);
insert into student values(2, '唐僧', 67, 98, 56);
insert into student values(3, '孙悟空', 87, 78, 77);
insert into student values(4, '老妖婆', 88, 98, 90);
insert into student values(5, '红孩儿', 82, 84, 67);
insert into student values(6, '如来佛祖', 55, 85, 45);
insert into student values(7, '菩萨', 75, 65, 30);

--将所有姓唐的学生成绩增加 %60
select name, (chinese+math+english)*1.6 as total from student where name like '唐%';

--查询姓如并且 id 大于 5 的学生
select * from student where name like '如%' and id > 5;

--查询总分大于 200 分的并且数学成绩小于语文成绩的姓唐的学生
select * from student where (math+english+chinese) > 200 and math < chinese and name like '唐%';

--查询数学成绩为 89、90、91 的学生
select * from student where math=89 or math=90 or math=91; --推荐
select * from student where math in(89,90,91);

--对总分进行排序后从高到低输出且命名为 total
select id, name, math+english+chinese as total from student order by total desc;

--统计数学成绩大于等于 90 的人
select * from student where math > 90;

--按照学生的 id 进行升序排序每页显示两条记录，请分别显示第一条、第二条、第三条
select * from student limit 0,3;
select * from student limit 3,3;
select * from student limit 6,3;