import 'package:flutter/material.dart';

class HomeScreen extends StatelessWidget {
  const HomeScreen({super.key});

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
                    Icons.home,
                    color: Color.fromARGB(255, 26, 43, 76),
                    size: 100,
                  ),
                  Text(
                    "Home",
                    style: TextStyle(
                      fontStyle: FontStyle.italic,
                      color: Color.fromARGB(255, 77, 182, 172),
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
