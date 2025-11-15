from password_gen import generate_password
import tkinter as tk

def on_generate():
    try:
        length = int(length_entry.get())
        password = generate_password(
            length,
            exclude_ambiguous=amb_var.get()
        )
        output_entry.delete(0, tk.END)
        output_entry.insert(0, password)

    except Exception as e:
        output_entry.delete(0, tk.END)
        output_entry.insert(0, f"Error: {e}")


# Window
window = tk.Tk()
window.title("Simple Password Generator")
window.geometry("300x200")

# Length
tk.Label(window, text="Password Length:").pack()
length_entry = tk.Entry(window)
length_entry.insert(0, "16")
length_entry.pack()

# Ambiguous checkbox
amb_var = tk.BooleanVar(value=False)
tk.Checkbutton(window, text="Exclude ambiguous (l,1,O,0,I)", variable=amb_var).pack()

# Button
tk.Button(window, text="Generate", command=on_generate).pack(pady=10)

# Output
output_entry = tk.Entry(window, font=("Consolas", 12), width=25)
output_entry.pack()

window.mainloop()
