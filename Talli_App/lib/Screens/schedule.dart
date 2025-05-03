import 'package:flutter/material.dart';

class ScheduleScreen extends StatelessWidget {
  const ScheduleScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Positioned(
              child: Column(
                children: [
                  Icon(
                    Icons.calendar_month,
                    color: Color.fromARGB(255, 8, 153, 13),
                    size: 100,
                  ),
                  Text(
                    "Schedule",
                    style: TextStyle(
                      fontStyle: FontStyle.italic,
                      color: Colors.deepOrange,
                      fontSize: 80
                    ),
                  )
                ],
              )
            )
            
          ],
        ),
      ),
    );
  }
}
