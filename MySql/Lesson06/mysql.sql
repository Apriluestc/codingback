--表的增删改查
--增加
create table user(
	id int unsigned primary key;
	good_name varchar(20) not null default '';
	price float not null default 0.0
);
insert into user values(100, '牛排', '78.5');
insert into user values(102, '披萨', 27.5);
select * from goods;
--增加进阶
insert into user values(101, 'ccc', 20.5);
--含有主键的值更新
insert into user values () on dumplicate key update;
--更新
update user set id = 2;
update user set price = 10.8;
--user 表中有5条ccc产品.我们希望将前三条改为ddd
update user set good_name = 'ddd' where
	good_name = 'ccc' limit 3;
--删除
delete from user where id = 101;
--复制表结构
create table good like user;
--复制数据
insert into good select * from user;
--删除整个表的数据但是表结构还在
delete from good;