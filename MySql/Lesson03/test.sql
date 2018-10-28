----
--test.sql

--有一个商店的数据，记录客户及购物情况，有以下三个表组成：
--商品goods(商品编号goods_ id，商品名goods_ name, 单价unitprice, 商品类别category, 供应商provider)
--客户customer(客户号customer_ id,姓名name,住址address,邮箱email,性别sex，身份证card_id) 
--购买purchase(购买订单号order_ id,客户号customer_ id,商品号goods_ id,购买数量nums)
--要求：
--每个表的主外键 客户的姓名不能为空值 邮箱不能重复 客户的性别(男，女)

--创建数据库

create database if not exists test 
default character set utf8;

--选择数据库

use test;

--商品

create table if not exists goods
(
    goods_id int unsigned primary key  auto_increment comment '商品编号', 
	goods_name varchar(100) not null comment '商品名称', 
	unitprice int not null default 0 comment '单价:分',    
	category varchar(32) comment '商品分类',
    provider varchar(100) not null comment '商品供应者' 
); 

--插入----------+goods+----------
insert into goods (goods_id, goods_name, unitprice, category, provider) values (0001, '牛排', 100, '熟食', '沃尔玛');
insert into goods (goods_id, goods_name, unitprice, category, provider) values (0002, '火腿', 10, '熟食', '迪拜');
insert into goods (goods_id, goods_name, unitprice, category, provider) values (0003, '鸡肉', 23, '生食', '加仑');
insert into goods (goods_id, goods_name, unitprice, category, provider) values (0004, '沙琪玛', 5, '零食', '沃尔玛');
insert into goods (goods_id, goods_name, unitprice, category, provider) values (0005, '奶茶', 18, '饮料', '飞利浦');

--客户
--创建表

create table if not exists customer
(
	customer_id int primary key comment '客户编号',
	name varchar(32) not null comment '客户名称',
	address varchar(100) not null comment '客户住址',
	email varchar(60) not null unique comment '客户邮箱',
    sex enum('男','女') not null default '男' comment '客户性别',
    card_id varchar(20) not null unique 
);

--查看表
desc goods;

--插入----------+customer+-------------
insert into customer (customer_id, name, address, email, sex, card_id) values (0001, 'Jams', '沁园小区', '123@Liu.com', '男', '610428199801232230');
insert into customer (customer_id, name, address, email, sex, card_id) values (0002, 'Toms', '金华小区', '122@Liu.com', '男', '610428199801232231');
insert into customer (customer_id, name, address, email, sex, card_id) values (0003, 'Alice', '沁园小区', '12223@Liu.com', '男', '610428199801232232');
insert into customer (customer_id, name, address, email, sex, card_id) values (0004, 'Wodl', '世纪花园', '122@Liuop.com', '女', '610428199801232233');
insert into customer (customer_id, name, address, email, sex, card_id) values (0005, 'Jal', '科大', '152@Liu.com', '女', '610428199801232443');

--购买

create table if not exists purchase
(
	order_id varchar(30) not null primary key comment '购买订单号',    
	customer_id int unsigned not null comment '客户号',  
	goods_id int unsigned not null comment '商品号',
    nums int not null default 0 comment '购买数量'
);

--表的查询
select * from goods;
select * from customer;
--创建一个使用utf8字符集的 test1 数据库
create database test1 charset = utf8;
--创建一个使用utf字符集，并带校对规则的 test2 数据库。
create database test2 charset = utf8 collate utf8_general_ci;

-- 查看系统默认字符集以及校验规ze
show variables like 'character_set_database'; 
show variables like 'collation_database';

--查看数据库支持的字符集
show charset;

-- 查看数据库支持的字符集校验规则 
show collation;

--校验规则对数据库的影响 

--查看数据库
 show databases;
 --显示创建语句
 
show create database test;
示例:
mysql> show create database mytest; 
		+----------+-----------------------------------------------------------------+ 
		| Database | Create Database                                                 |
		+----------+-----------------------------------------------------------------+
		| mysql    | CREATE DATABASE `mytest` /*!40100 DEFAULT CHARACTER SET utf8 */ | 
		+----------+-----------------------------------------------------------------+
--修改数据库:
		1.修改表的字符集
		mysql> alter database mytest charset=gbk; 
--删除数据库
		drop database if exists test;
--备份或回复:
		mysqldump -u root -p 密码 -B 数据库名 > 数据库备份存储的文件路径
		mysqldump -u root -p mytest > ./mytest.sql
		source /root/Desktop/mytest.sql；
--查看连接情况:
		show processlist;
		mysql> show processlist; 
		+----+------+-----------+------+---------+------+-------+------------------+ 
		| Id | User | Host      | db   | Command | Time | State | Info             |
		+----+------+-----------+------+---------+------+-------+------------------+
		|  2 | root | localhost | test | Sleep   | 1386 |       | NULL             |
		|  3 | root | localhost | NULL | Query   |    0 | NULL  | show processlist |
		+----+------+-----------+------+---------+------+-------+------------------+
		

		:
		



























