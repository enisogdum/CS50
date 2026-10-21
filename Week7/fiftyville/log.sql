-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find creme scene descriptions

SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';

-- Theft of the CS50 duck took place at 10:15am at the Humphrey
--Street bakery. Interviews were conducted today with three
--witnesses who were present at the time – each of their
--interview transcripts mentions the bakery.
--Littering took place at 16:36. No known witnesses.

-- Find suspects
SELECT name, transcript
FROM interviews
WHERE year = 2025 AND month = 7 AND day = 28;

--Sometime within ten minutes of the theft, I saw the
--thief get into a car in the bakery parking lot

--I was walking by the ATM on Leggett
--Street and saw the thief there withdrawing some money.

--As the thief was leaving the bakery, they called
--someone who talked to them for less than a minute.
 -- In the call, I heard the thief say that they were
--planning to take the earliest flight out of Fiftyville tomorrow.

-- bakery parking lot
SELECT * FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND activity = 'exit';

--5P2BI95 94KL13X
--6P58WS2 4328GD8
--G412CB7 L93JTIZ
--322W7JE 0NTHK55

--bank accounts
SELECT * FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON people.id = bank_accounts.person_id
WHERE year = 2025 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

--+-----+----------------+------+-------+-----+----------------+------------------+--------+
--| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
--+-----+----------------+------+-------+-----+----------------+------------------+--------+
--| 246 |       28500762 | 2025 |     7 |  28 | Leggett Street | withdraw         |     48 |
--| 264 |       28296815 | 2025 |     7 |  28 | Leggett Street | withdraw         |     20 |
--| 266 |       76054385 | 2025 |     7 |  28 | Leggett Street | withdraw         |     60 |
--| 267 |       49610011 | 2025 |     7 |  28 | Leggett Street | withdraw         |     50 |
--| 269 |       16153065 | 2025 |     7 |  28 | Leggett Street | withdraw         |     80 |
--| 288 |       25506511 | 2025 |     7 |  28 | Leggett Street | withdraw         |     20 |
--| 313 |       81061156 | 2025 |     7 |  28 | Leggett Street | withdraw         |     30 |
--| 336 |       26013199 | 2025 |     7 |  28 | Leggett Street | withdraw         |     35 |
--+-----+----------------+------+-------+-----+----------------+------------------+--------+

-- Find the phone calls
SELECT * FROM phone_calls
WHERE year = 2025 AND month = 7 AND day = 28
AND duration <= 60;

--+-----+----------------+----------------+------+-------+-----+----------+
--| id  |     caller     |    receiver    | year | month | day | duration |
--+-----+----------------+----------------+------+-------+-----+----------+
--| 221 | (130) 555-0289 | (996) 555-8899 | 2025 |     7 |  28 |       51 |
--| 224 | (499) 555-9472 | (892) 555-8872 | 2025 |     7 |  28 |       36 |
--| 233 | (367) 555-5533 | (375) 555-8161 | 2025 |     7 |  28 |       45 |
--| 234 | (609) 555-5876 | (389) 555-5198 | 2025 |     7 |  28 |       60 |
--| 251 | (499) 555-9472 | (717) 555-1342 | 2025 |     7 |  28 |       50 |
--| 254 | (286) 555-6063 | (676) 555-6554 | 2025 |     7 |  28 |       43 |
--| 255 | (770) 555-1861 | (725) 555-3243 | 2025 |     7 |  28 |       49 |
--| 261 | (031) 555-6622 | (910) 555-3251 | 2025 |     7 |  28 |       38 |
--| 279 | (826) 555-1652 | (066) 555-9701 | 2025 |     7 |  28 |       55 |
--| 281 | (338) 555-6650 | (704) 555-2131 | 2025 |     7 |  28 |       54 |
--+-----+----------------+----------------+------+-------+-----+----------+

--Find the flights
SELECT * FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE airports.city = 'Fiftyville'
AND year = 2025 AND month = 7 AND day = 29;

--+--+-----------------+--------------------+----+-----+---+----+------+--+------------+---------------------------+----------+
--|id|origin_airport_id|destination_airpo...|year|month|day|hour|minute|id|abbreviation|         full_name         |   city   |
--+--+-----------------+--------------------+----+-----+---+----+------+--+------------+---------------------------+----------+
--|18|                8|                   6|2025|    7| 29|  16|     0| 8|CSF         |Fiftyville Regional Airport|Fiftyville|
--|23|                8|                  11|2025|    7| 29|  12|    15| 8|CSF         |Fiftyville Regional Airport|Fiftyville|
--|36|                8|                   4|2025|    7| 29|   8|    20| 8|CSF         |Fiftyville Regional Airport|Fiftyville|
--|43|                8|                   1|2025|    7| 29|   9|    30| 8|CSF         |Fiftyville Regional Airport|Fiftyville|
--|53|                8|                   9|2025|    7| 29|  15|    20| 8|CSF         |Fiftyville Regional Airport|Fiftyville|
--+--+-----------------+--------------------+----+-----+---+----+------+--+------------+---------------------------+----------+

--Relation license plate between people and logs

SELECT DISTINCT(name) FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute <= 25 AND bakery_security_logs.activity = 'exit' AND phone_calls.duration <= 60;
--+--------+
--|  name  |
--+--------+
--| Bruce  |
-- Sofia  |
--| Diana  |
--| Kelsey |
--+--------+

--passengers
SELECT DISTINCT people.name
FROM passengers
JOIN people
    ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id IN (
    -- First flight leaving Fiftyville on July 29, 2025
    SELECT id
    FROM flights
    WHERE origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
      AND year = 2025
      AND month = 7
      AND day = 29
    ORDER BY hour ASC
    LIMIT 1
)
AND people.id IN (
    -- People who exited the bakery before or at 10:25
    -- and made a short call on July 28
    SELECT DISTINCT p.id
    FROM people AS p
    JOIN bakery_security_logs AS b
        ON p.license_plate = b.license_plate
    JOIN phone_calls AS c
        ON c.caller = p.phone_number
    WHERE b.year = 2025
      AND b.month = 7
      AND b.day = 28
      AND b.hour = 10
      AND b.minute <= 25
      AND b.activity = 'exit'
      AND c.year = 2025
      AND c.month = 7
      AND c.day = 28
      AND c.duration < 60
)
AND people.id IN (
    -- People who withdrew money from Leggett Street ATM
    SELECT ba.person_id
    FROM atm_transactions AS a
    JOIN bank_accounts AS ba
        ON a.account_number = ba.account_number
    WHERE a.year = 2025
      AND a.month = 7
      AND a.day = 28
      AND a.atm_location = 'Leggett Street'
      AND a.transaction_type = 'withdraw'
);

--Destionation Airport

SELECT * FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
WHERE flights.id = 36;

--find receiver

SELECT name FROM people
WHERE phone_number = '(375) 555-8161';
