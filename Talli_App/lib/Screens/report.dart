import 'package:flutter/material.dart';

class ReportScreen extends StatelessWidget {
  const ReportScreen({super.key});

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
                    Icons.bar_chart,
                    color: Color.fromARGB(255, 8, 153, 13),
                    size: 100,
                  ),
                  Text(
                    "Report",
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
