import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Send
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.TextStyle
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.compose.ui.window.Window
import androidx.compose.ui.window.application
import kotlinx.coroutines.delay
import java.time.LocalDateTime
import java.time.format.DateTimeFormatter

// Data classes for messages and users
data class Message(val id: Int, val user: User, val text: String, val timestamp: LocalDateTime)
data class User(val id: Int, val name: String, val color: Color)

// Main function to launch the chat application
fun main() = application {
    Window(onCloseRequest = ::exitApplication, title = "Kotlin Chatroom") {
        ChatRoomApp()
    }
}

@Composable
fun ChatRoomApp() {
    // Sample users
    val users = listOf(
        User(1, "Alice", Color(0xFFFFB6C1)),
        User(2, "Bob", Color(0xFFADD8E6)),
        User(3, "Charlie", Color(0xFF90EE90)),
        User(4, "Diana", Color(0xFFFFD700))
    )
    
    // Current user (in a real app, this would come from login)
    val currentUser = users[0]
    
    // State for messages and new message text
    var messages by remember { mutableStateOf(listOf<Message>()) }
    var newMessage by remember { mutableStateOf("") }
    
    // Function to send a message
    fun sendMessage() {
        if (newMessage.isNotBlank()) {
            val newMsg = Message(
                id = messages.size + 1,
                user = currentUser,
                text = newMessage,
                timestamp = LocalDateTime.now()
            )
            messages = messages + newMsg
            newMessage = ""
            
            // Simulate responses from other users
            if (messages.size % 3 == 0) {
                val randomUser = users.filter { it != currentUser }.random()
                simulateResponse(randomUser, messages)
            }
        }
    }
    
    // UI layout
    Column(
        modifier = Modifier.fillMaxSize().padding(16.dp),
        verticalArrangement = Arrangement.SpaceBetween
    ) {
        // Header
        Text(
            "Kotlin Chatroom", 
            style = TextStyle(fontSize = 24.sp, fontWeight = FontWeight.Bold),
            modifier = Modifier.padding(bottom = 16.dp)
        )
        
        // Messages list
        LazyColumn(
            modifier = Modifier.weight(1f).fillMaxWidth(),
            verticalArrangement = Arrangement.spacedBy(8.dp)
        ) {
            items(messages) { message ->
                MessageBubble(message, message.user == currentUser)
            }
        }
        
        // Input area
        Row(
            modifier = Modifier.fillMaxWidth().padding(top = 16.dp),
            verticalAlignment = Alignment.CenterVertically
        ) {
            OutlinedTextField(
                value = newMessage,
                onValueChange = { newMessage = it },
                placeholder = { Text("Type your message...") },
                modifier = Modifier.weight(1f),
                singleLine = true
            )
            
            Spacer(modifier = Modifier.width(8.dp))
            
            Button(
                onClick = { sendMessage() },
                enabled = newMessage.isNotBlank()
            ) {
                Icon(Icons.Default.Send, contentDescription = "Send")
                Spacer(modifier = Modifier.width(4.dp))
                Text("Send")
            }
        }
    }
}

@Composable
fun MessageBubble(message: Message, isCurrentUser: Boolean) {
    val alignment = if (isCurrentUser) Alignment.End else Alignment.Start
    val bubbleColor = if (isCurrentUser) MaterialTheme.colors.primary else message.user.color
    val textColor = if (isCurrentUser) Color.White else Color.Black
    
    Column(
        modifier = Modifier.fillMaxWidth(),
        horizontalAlignment = alignment
    ) {
        // User name
        if (!isCurrentUser) {
            Text(
                text = message.user.name,
                style = TextStyle(fontSize = 12.sp, fontWeight = FontWeight.Bold),
                modifier = Modifier.padding(bottom = 4.dp, start = 8.dp)
            )
        }
        
        // Message bubble
        Box(
            modifier = Modifier
                .widthIn(max = 280.dp)
                .background(
                    color = bubbleColor,
                    shape = RoundedCornerShape(
                        topStart = if (isCurrentUser) 16.dp else 0.dp,
                        topEnd = if (isCurrentUser) 0.dp else 16.dp,
                        bottomStart = 16.dp,
                        bottomEnd = 16.dp
                    )
                )
                .padding(horizontal = 16.dp, vertical = 10.dp)
        ) {
            Text(
                text = message.text,
                color = textColor,
                style = TextStyle(fontSize = 14.sp)
            )
        }
        
        // Timestamp
        Text(
            text = message.timestamp.format(DateTimeFormatter.ofPattern("HH:mm")),
            style = TextStyle(fontSize = 10.sp, color = Color.Gray),
            modifier = Modifier.padding(top = 4.dp, start = 8.dp, end = 8.dp)
        )
    }
}

// Simulate responses from other users
fun simulateResponse(user: User, currentMessages: List<Message>) {
    val responses = listOf(
        "Hello there!",
        "How are you doing?",
        "I was just thinking about that too!",
        "Interesting point of view.",
        "Let's discuss this more later.",
        "Can you explain that further?",
        "I agree with you.",
        "Have you seen the latest update?",
        "What do you think about the new features?",
        "Thanks for sharing!"
    )
    
    // Use a coroutine to delay the response
    kotlinx.coroutines.GlobalScope.launch {
        delay((1000..3000).random().toLong()) // Random delay between 1-3 seconds
        
        val newMsg = Message(
            id = currentMessages.size + 1,
            user = user,
            text = responses.random(),
            timestamp = LocalDateTime.now()
        )
        
        // In a real application, we would update the state properly
        // This is simplified for demonstration
    }
}
