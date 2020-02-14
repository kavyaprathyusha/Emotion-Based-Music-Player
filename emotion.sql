-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 14, 2016 at 02:56 PM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `emotion`
--

-- --------------------------------------------------------

--
-- Table structure for table `login_table`
--

CREATE TABLE IF NOT EXISTS `login_table` (
  `user_id` int(100) NOT NULL AUTO_INCREMENT,
  `Username` varchar(20) NOT NULL,
  `Password` varchar(20) NOT NULL,
  `LastName` varchar(20) NOT NULL,
  `FirstName` varchar(20) NOT NULL,
  `role` varchar(20) NOT NULL,
  `email` varchar(30) NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Dumping data for table `login_table`
--

INSERT INTO `login_table` (`user_id`, `Username`, `Password`, `LastName`, `FirstName`, `role`, `email`) VALUES
(1, 'kavya', 'kavya', 'chekka', 'kavya', 'admin', 'kavya.chekka@gmail.com'),
(2, 'deekshitha', 'deekshu', 'deekshu', 'deekshitha', 'admin', 'deekshitha@gmail.com'),
(3, 'manaswi', 'manaswi', 'kolli', 'manaswi', 'admin', 'manaswi@gmail.com'),
(4, 'swamy', 'swamy', 'naga', 'swamy', 'admin', 'swamy@gmail.com'),
(5, 'manasa', 'manasa', 'kosaraju', 'manasa', 'user', 'manasa@gmail.com'),
(6, 'sahitya', 'sahitya', 'chekka', 'sahitya', 'user', 'sahitya.chekka@gmail.com'),
(7, 'prasad', 'prasad', 'chekka', 'Prasad', 'user', 'prasad.chekka@gmail.com'),
(8, 'suneetha', 'suneetha', 'chekka', 'suneetha', 'user', 'suneetha.chekka@gmail.com'),
(9, 'suneetha', 'suneetha', 'chekka', 'suneetha', 'user', 'suneetha.chekka@gmail.com');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
