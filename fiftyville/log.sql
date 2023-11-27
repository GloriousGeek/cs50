-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Quering from the data as per the intel provided to get leads - 10:15am at the bakery.
SELECT * FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2021 AND street = 'Humphrey Street';

-- Query from the interviews to find leads mentioning bakery
SELECT * FROM interviews
WHERE day = 28 AND month = 7 AND year = 2021;

-- Ruth's intel - Security footage 10 mins aftr CS
SELECT * FROM bakery_security_logs
WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit';

-- Searching all people affiliated with the license_plate from the query above
SELECT * FROM people
WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit');

-- 
SELECT * FROM atm_transactions
WHERE atm_location = 'Leggett Street' AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw';

