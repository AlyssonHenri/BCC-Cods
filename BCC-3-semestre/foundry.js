const rolltable = game.tables.getName("Aflições");
const theActor = game.actors.get(args[0].actorData._id);
const actorName = args[0].actorData.name;
const giftItem = args[0].item;
//theActor.data.items.find(i => i.name === 'Holiday Gift');
async function GiveGift() 
{ 
    //Play sound
    AudioHelper.play
    (    
        {      
            src: "assets/audio/sfx/open-gift.ogg",
            volume: 0.5,
            autoplay: true,
            loop: false,
        },    
        false  
    );

    //Roll for the item description  
    let result = await rolltable.roll();
    let itemDesc = await result.results[0].data.text; 
    /*let imgPath = await result.results[0].data.img;*/  
    //create the opened gift item and get its data from promises  
    setTimeout(async function theUnwrapping() 
    { theActor      
        .createEmbeddedDocuments
        ("Item",
            [        
                {          
                    name: "Opened Holiday Gift",          
                    type: "loot",          
                    img: "assets/art/icons/Dusty_Wintersday_Gift.png",          
                    data: 
                    {            
                        description: 
                        {              
                            value: itemDesc,              
                            unidentified: "false",            
                        },            
                        source: "Holiday Gift",           
                        quantity: 1,            
                        equipped: false,            
                        identified: true,          
                    },        
                },      
            ]
        )      
        .then(async (g) => 
        {
            g[0].roll({ createMessage: false }).then(async (r) => 
            {
                //create a combined chat card to show what they got          
                await ChatMessage.create
                (            
                    {              
                        speaker: { alias: actorName },
                        content: 
                        `<hr><div style="color: black; font-size: 1.2em;"> ${actorName} opens their gift and receives:</div><p> ${r.content}`,
                    },
                    { chatBubble: false } 
                );
            });     
        });  
    }, 
    3000);
}
GiveGift();