import 'package:flutter/material.dart';

class ProfileScreen extends StatelessWidget {
  final bool isSignedIn = true;

  const ProfileScreen({super.key}); // Change to false to test sign-in section

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.deepOrange,
      body: SafeArea(
        child: isSignedIn ? _buildProfileContent(context) : _buildSignInPrompt(),
      ),
    );
  }

  Widget _buildProfileContent(BuildContext context) {
    return Column(
      children: [
        // 🔸 Profile Header
        Container(
          padding: const EdgeInsets.all(20),
          child: Column(
            children: [
              
              const Text(
                'Martina Alex',
                style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold, color: Colors.white),
              ),
              const Text(
                'martina.alex0509@gmail.com',
                style: TextStyle(fontSize: 16, color: Colors.white70),
              ),
              const SizedBox(height: 20),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: const [
                  _StatColumn(label: 'Income', amount: '\$3,214', color: Colors.green),
                  _StatColumn(label: 'Expense', amount: '\$1,640', color: Colors.red),
                ],
              ),
              const SizedBox(height: 12),
              Stack(
                alignment: Alignment.center,
                children: [
                  Container(
                    width: 160,
                    height: 160,
                    decoration: BoxDecoration(
                      shape: BoxShape.circle,
                      color: Colors.white,
                    ),
                  ),
                  const CircleAvatar(
                    radius: 70,
                    backgroundColor: Colors.white,
                  ),
                ],
              )
              
            ],
          ),
        ),

        // 🔹 White Details Section
        Expanded(
          child: Container(
            width: double.infinity,
            padding: const EdgeInsets.all(20),
            decoration: const BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.vertical(top: Radius.circular(30)),
            ),
            child: SingleChildScrollView(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  const Text('General', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
                  const SizedBox(height: 10),
                  _buildListTile(Icons.settings, 'Profile Settings'),
                  _buildListTile(Icons.lock, 'Change Password'),
                  _buildListTile(Icons.notifications, 'Notification'),
                  _buildListTile(Icons.history, 'Transaction History'),
                  const Divider(height: 40),

                  const Text('Tally Details', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
                  const SizedBox(height: 10),
                  _buildDetailRow('Departments Assigned:', '5'),
                  _buildDetailRow('Branch:', 'Nairobi HQ'),
                  _buildDetailRow('Access Level:', 'Supervisor'),
                  _buildDetailRow('Sessions Created:', '12'),
                ],
              ),
            ),
          ),
        ),
      ],
    );
  }

  Widget _buildListTile(IconData icon, String title) {
    return ListTile(
      contentPadding: EdgeInsets.zero,
      leading: Icon(icon, color: Colors.deepOrange),
      title: Text(title),
      trailing: const Icon(Icons.arrow_forward_ios, size: 16),
      onTap: () {},
    );
  }

  Widget _buildDetailRow(String label, String value) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 6),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(label, style: const TextStyle(fontWeight: FontWeight.w500)),
          Text(value, style: const TextStyle(color: Colors.black54)),
        ],
      ),
    );
  }

  Widget _buildSignInPrompt() {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(24),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const Icon(Icons.person_outline, size: 100, color: Colors.white),
            const SizedBox(height: 20),
            const Text(
              'You are not signed in',
              style: TextStyle(color: Colors.white, fontSize: 20),
            ),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: () {
                // Handle sign-in navigation
              },
              style: ElevatedButton.styleFrom(
                backgroundColor: Colors.white,
                foregroundColor: Colors.deepOrange,
                padding: const EdgeInsets.symmetric(horizontal: 32, vertical: 16),
              ),
              child: const Text('Sign In'),
            ),
          ],
        ),
      ),
    );
  }
}

class _StatColumn extends StatelessWidget {
  final String label;
  final String amount;
  final Color color;

  const _StatColumn({required this.label, required this.amount, required this.color});

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Text(label, style: const TextStyle(color: Colors.white70)),
        const SizedBox(height: 5),
        Text(amount, style: TextStyle(color: color, fontSize: 18, fontWeight: FontWeight.bold)),
      ],
    );
  }
}
