A program to read dialogues from a file, and play it.
Pass in the name of the file as a command line argument

Format for the dialogue file:
nodes: [total_nodes_in_your_conversation]     // the highest node
*** [node_number] ***
	Title: [NPC_talk_text]
	Options: ([your_option]|[pointer_to_node_put_0_to_lose]|[op. put 1 here if this is the end game option]) ([another_options_this_is_optional]|[number]|[op.])

*** [another_node_number_to_specify] ***
	...			// title
	...			// options

// more nodes...