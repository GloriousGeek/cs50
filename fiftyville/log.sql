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

-- Searching all people affiliated with the license_plate from the query above. We got names of people.
SELECT * FROM people
WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit');

-- Eugene's intel
SELECT * FROM atm_transactions
WHERE atm_location = 'Leggett Street' AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw';

-- We got account_number of 8 people. Lets query the bank_accounts and link it to people and lice_plate from Bakery logs
SELECT * FROM bank_accounts
WHERE account_number IN
    (SELECT account_number FROM atm_transactions
    WHERE atm_location = 'Leggett Street'
    AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw')
    AND person_id IN
        (SELECT id FROM people
        WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
        WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit'));

-- Linking the above shortlisted people with people_id to get the names
SELECT * FROM people
WHERE id IN (SELECT person_id FROM bank_accounts
WHERE account_number IN
    (SELECT account_number FROM atm_transactions
    WHERE atm_location = 'Leggett Street'
    AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw')
    AND person_id IN
        (SELECT id FROM people
        WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
        WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit')));

-- Linking the above output 'name' with 'caller' on phone_calls to narrow-down
SELECT * FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE people.id IN (SELECT person_id FROM bank_accounts
WHERE account_number IN
    (SELECT account_number FROM atm_transactions
    WHERE atm_location = 'Leggett Street'
    AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw')
    AND person_id IN
        (SELECT id FROM people
        WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
        WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit')))
    AND day = 28 AND month = 7 AND year = 2021 AND duration < 60;

